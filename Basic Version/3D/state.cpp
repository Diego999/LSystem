#include "state.h"

State::State()
{
    position    = QVector3D(0.0, 0.0, 0.0);
    direction   = QVector3D(0.0, 0.0, 1.0);
}

State::State(QVector3D position, QVector3D direction)
{
    this->position  = position;
    this->direction = direction;
}

void State::setPosition(QVector3D newPosition)
{
    position.setX(newPosition.x());
    position.setY(newPosition.y());
    position.setZ(newPosition.z());
}

QVector3D State::getPosition() const
{
    return position;
}

void State::setDirection(QVector3D newDirection)
{
    direction.setX(newDirection.x());
    direction.setY(newDirection.y());
    direction.setZ(newDirection.z());
}

QVector3D State::getDirection() const
{
    return direction;
}

