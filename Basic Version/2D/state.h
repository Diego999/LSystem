#ifndef STATE_H
#define STATE_H

#include <QtCore/qmath.h>
#include <QtCore>

class State
{
private:
    QPointF position;
    qreal   angle;

public:
    State();
    State(QPointF position, qreal angle);
    void        setPosition(QPointF newPosition);
    QPointF     getPosition();
    void        setAngle(qreal newAngle);
    qreal       getAngle();
};

#endif // STATE_H
