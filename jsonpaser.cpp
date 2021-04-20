#include "jsonpaser.h"
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QDebug>

JsonPaser::JsonPaser()
{
    QJsonObject *company = openStructFile();
    printCompany(company);
    delete company;
}

JsonPaser::~JsonPaser()
{
}

void JsonPaser::printCompany(QJsonObject *company) const
{
    if(!company) {
        return;
    }
    QStringList departmentNames = company->keys();
    qDebug() << "departments:";
    QJsonArray departments = (*company)["一棵葱公司"].toArray();
    for(int i = 0; i < departments.size(); ++i) {
        QJsonObject department = departments[i].toObject();
        for(auto it = department.constBegin(); it != department.constEnd(); ++it) {
            QJsonObject postions = it.value().toObject();
            QStringList poss = postions.keys();
            for(auto i : poss) {
                qDebug() << i;
            }
        }
    }
}

QJsonObject *JsonPaser::openStructFile()
{
    QFile jsonfile(JSON_FILE);
    if(!jsonfile.open(QFile::ReadOnly)) {
        return nullptr;
    }
    QByteArray string = jsonfile.readAll();
    jsonfile.close();

    QJsonDocument jsonDoc(QJsonDocument::fromJson(string));
    QJsonObject struct_json = jsonDoc.object();
    //判断json的 键 里是否包含 "一棵葱公司"
    if(struct_json.contains("一棵葱公司")) {
        qDebug() << "contains 一棵葱公司";
        return new QJsonObject(struct_json);
    }
    return nullptr;
}
