#include "include/parser/sequenceparser.h"

#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QApplication>
#include <QDebug>

SequenceParser::SequenceParser(const QString& filepath):filePath(filepath)
{
    getRules();
}

void SequenceParser::getRules()
{
    if(!QFile::exists(filePath))
    {
        QMessageBox::critical(0,QApplication::tr("CRITICAL ERROR"),QApplication::tr("The file doesn't exist !"));
        exit(EXIT_FAILURE);
    }

    QFile file(filePath);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::critical(0,QApplication::tr("CRITICAL ERROR"),QApplication::tr("The file cannot be reader !"));
        file.close();
        exit(EXIT_FAILURE);
    }

    QTextStream stream(&file);
    while(!stream.atEnd())
    {
        QString line = stream.readLine().trimmed();

        if(line.length() > 0)
        {
            QStringList sl = line.split("->", QString::SkipEmptyParts);
            if(sl.length() > 1)
                rules[*sl[0].trimmed().data()] = sl[1].trimmed();
        }
    }
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
