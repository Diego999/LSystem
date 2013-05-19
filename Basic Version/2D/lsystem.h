#ifndef LSYSTEM_H
#define LSYSTEM_H

#include <QtCore>

class LSystem
{
private:
    QHash<QString, QString> rules;
    QString                 sequence;
    QString                 filePath;
public:
    LSystem();
    void getRules(QString filePath);
    QString substitute(QString initiator, int deep);
    void reset();
};

#endif // LSYSTEM_H
