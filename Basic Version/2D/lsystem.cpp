#include "lsystem.h"
#include <iostream>

LSystem::LSystem()
{
    sequence  = "";
}

void LSystem::getRules(QString filePath)
{
    if(QFile::exists(filePath))
    {
        this->filePath = filePath;
        QFile fin(filePath);
        if(!fin.open(QIODevice::ReadOnly|QIODevice::Text))
        {
            return;
        }
        QTextStream flux(&fin);

        while(!flux.atEnd())
        {
            QString line = flux.readLine().trimmed();
            if(line.length() > 0)
            {
                QStringList sl = line.split("->", QString::SkipEmptyParts);
                if(sl.length() > 1)
                    rules[sl[0].trimmed()] = sl[1].trimmed();
            }
        }
        fin.close();
    }
}

QString LSystem::substitute(QString initiator, int deep)
{
    for(int i=0;i<deep;i++)
    {
        sequence = "";
        for(int letter=0;letter<initiator.length();letter++)
        {
            QHashIterator<QString, QString> it(rules);
            bool found = false;
            while(it.hasNext())
            {
                it.next();;
                if(initiator.at(letter) == it.key().at(0))
                {
                    sequence += it.value();
                    found = true;
                    break;
                }
            }
            if(!found)  sequence += initiator.at(letter);
        }
        initiator = QString(sequence);
    }
    return sequence;
}

void LSystem::reset()
{
    sequence  = "";
}
