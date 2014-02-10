#include "include/turtle/state.h"

State::State(const QVector3D& position, const QVector3D& direction)
    :position(position),direction(direction),defaultPosition(position),defaultDirection(direction),oldPosition(position)
{

}

void State::forward(qreal stepLength)
{
    oldPosition = position;
    position += stepLength*direction;
}

void State::setDefaultPositionAndDirection()
{
    position = defaultPosition;
    direction = defaultDirection;
}

void State::setPosition(const QVector3D& newPosition)
{
    oldPosition = position;
    position = newPosition;
}

void State::setDirection(const QVector3D& newDirection)
{
    direction = newDirection;
}

QVector3D State::getOldPosition() const
{
    return oldPosition;
}

QVector3D State::getPosition() const
{
    return position;
}

QVector3D State::getDirection() const
{
    return direction;
}
