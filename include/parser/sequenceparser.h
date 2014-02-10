#ifndef SEQUENCEPARSER_H
#define SEQUENCEPARSER_H

#include <QHash>
#include <QString>
#include <QXmlStreamReader>
#include <QStringList>

class SequenceParser
{
public:
    SequenceParser(const QString& filepath);
    void getRules();
    QString substitute(const QString& initiator,const int deep);

    QString getName() const {return name;}
    QString getAxiom() const {return axiom;}
    qreal getStepLength() const {return stepLength;}
    qreal getAngle() const {return angle;}
    int getDeep() const {return deep;}
    QStringList getForwards() const {return forwards;}

private:
    static const QString NAME_KEY;
    static const QString ANGLE_KEY;
    static const QString AXIOM_KEY;
    static const QString DEEP_KEY;
    static const QString STEP_LENGTH;
    static const QString RULE_LEFT_KEY;
    static const QString RULE_RIGHT_KEY;
    static const QString FORWARD_KEY;

    QHash<QChar, QString> rules;
    QStringList forwards;
    QString filePath;
    QString name;
    qreal angle;
    qreal stepLength;
    QString axiom;
    int deep;
};

#endif // SEQUENCEPARSER_H
