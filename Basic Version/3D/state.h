#ifndef STATE_H
#define STATE_H

#include <QtCore/qmath.h>
#include <QtCore>
#include <QVector3D>

class State
{
private:
    QVector3D   position;
    QVector3D   direction;

public:
    State();
    State(QVector3D position, QVector3D direction);
    void        setPosition(QVector3D newPosition);
    QVector3D   getPosition() const;
    void        setDirection(QVector3D newDirection);
    QVector3D   getDirection() const;
};

#endif // STATE_H
