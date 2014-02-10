#include "include/parser/sequenceparser.h"

#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QApplication>
#include <QDebug>
#include <iostream>
const QString SequenceParser::NAME_KEY = "name";
const QString SequenceParser::ANGLE_KEY = "angle";
const QString SequenceParser::AXIOM_KEY = "axiom";
const QString SequenceParser::DEEP_KEY = "deep";
const QString SequenceParser::STEP_LENGTH = "step-length";
const QString SequenceParser::RULE_LEFT_KEY = "left";
const QString SequenceParser::RULE_RIGHT_KEY = "right";
const QString SequenceParser::FORWARD_KEY = "forward";

SequenceParser::SequenceParser(const QString& filepath):filePath(filepath),name(""),angle(0),stepLength(0),axiom(""),deep(0)
{
    getRules();
}

void SequenceParser::getRules()
{
    if(!QFile::exists(filePath))
    {
        std::cerr << "File doesn't exist !" << std::endl;
        exit(EXIT_FAILURE);
    }

    QFile file(filePath);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        std::cerr << "The file cannot be read !" << std::endl;
        file.close();
        exit(EXIT_FAILURE);
    }
    QXmlStreamReader reader(&file);

    QString lastEntry = "";

    while(!reader.atEnd() && !reader.hasError())
    {
        reader.readNext();
        if(reader.isStartElement())
        {
            QString _name = reader.name().toString();
            if(_name == NAME_KEY)
                name = reader.readElementText();
            else if(_name == DEEP_KEY)
                deep = reader.readElementText().toInt();
            else if(_name == ANGLE_KEY)
                angle = reader.readElementText().toDouble();
            else if(_name == STEP_LENGTH)
                stepLength = reader.readElementText().toDouble();
            else if(_name == AXIOM_KEY)
                axiom = reader.readElementText();
            else if(_name == RULE_LEFT_KEY)
            {
                lastEntry = reader.readElementText().trimmed();
                rules[*lastEntry.data()] = "";
            }
            else if(_name == RULE_RIGHT_KEY)
                rules[*lastEntry.data()] = reader.readElementText().trimmed();
            else if(_name == FORWARD_KEY)
                forwards << reader.readElementText();
        }
    }

    reader.clear();
    file.close();
}

QString SequenceParser::substitute(const QString& initiator, const int deep)
{
    if(deep != 0)
    {
        QString sequence("");
        for(QString::const_iterator it = initiator.constBegin(); it != initiator.constEnd(); ++it)
            if(rules.contains(*it))
                sequence += rules[*it];
            else
                sequence += *it;

        return substitute(sequence, deep-1);
    }
    else
        return initiator;
}
