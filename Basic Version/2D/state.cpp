#include "state.h"

State::State()
{
    position = QPointF(0.0, 0.0);
    angle = 0.0;
}

State::State(QPointF position, qreal angle)
{
    this->position = position;
    this->angle = angle;
}

void State::setPosition(QPointF newPosition)
{
    if(!newPosition.isNull())
    {
        position.setX(newPosition.x());
        position.setY(newPosition.y());
    }
}

QPointF State::getPosition()
{
    return position;
}

void State::setAngle(qreal newAngle)
{
    angle = newAngle;
}

qreal State::getAngle()
{
    return angle;
}
