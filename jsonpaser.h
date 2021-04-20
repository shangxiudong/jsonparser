#ifndef WIDGET_H
#define WIDGET_H

#define JSON_FILE ":struct.json"


class QJsonObject;
class JsonPaser
{

public:
    JsonPaser();
    ~JsonPaser();
    void printCompany(QJsonObject *company) const;
private:
    QJsonObject *openStructFile();

};

#endif // WIDGET_H
