#ifndef SEQUENCEPARSER_H
#define SEQUENCEPARSER_H

#include <QHash>
#include <QString>

class SequenceParser
{
public:
    SequenceParser(const QString& filepath);
    void getRules();
    QString substitute(const QString& initiator,const int deep);

private:
    QHash<QChar, QString> rules;
    QString filePath;
};

#endif // SEQUENCEPARSER_H
