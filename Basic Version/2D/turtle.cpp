#include "turtle.h"

Turtle::Turtle()
{
    state.setPosition(QPointF(0.0, 0.0));
    state.setAngle(0.0);
    stepLength = 1.0;
    stepAngle = 90.0;
}

Turtle::Turtle(QPointF startPosition, qreal startAngle, qreal stepLength, qreal stepAngle)
{
    state.setPosition(startPosition);
    state.setAngle(startAngle);
    this->stepLength = stepLength;
    this->stepAngle = stepAngle;
}

void Turtle::StatePush()
{
    stack.push(state);
}

void Turtle::StatePop()
{
    state = stack.pop();
}

QPointF Turtle::Move()
{
    /*
     *deg = rad * (180/pi) et rad = deg * ( pi/180)
     */
    qreal rad = state.getAngle() * (M_PI / 180.0);
    qreal dy = qSin(rad) * stepLength;
    qreal dx = qCos(rad) * stepLength;
    QPointF stop(state.getPosition().x() + dx, state.getPosition().y() + dy);
    state.setPosition(stop);
    return stop;
}

void Turtle::TurnLeft()
{
    qreal currentAngle = state.getAngle();
    state.setAngle(currentAngle - stepAngle);
}

void Turtle::TurnRight()
{
    qreal currentAngle = state.getAngle();
    state.setAngle(currentAngle + stepAngle);
}
