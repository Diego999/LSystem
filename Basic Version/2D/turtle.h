#ifndef TURTLE_H
#define TURTLE_H

#include <QtCore>
#include "state.h"

class Turtle
{
public:
    State           state;
    QStack<State>   stack;
    qreal           stepLength;
    qreal           stepAngle;

    Turtle();
    Turtle(QPointF startPosition, qreal startAngle, qreal stepLength, qreal stepAngle);
    void            StatePush();
    void            StatePop();
    QPointF         Move();
    void            TurnLeft();
    void            TurnRight();
};

#endif // TURTLE_H
