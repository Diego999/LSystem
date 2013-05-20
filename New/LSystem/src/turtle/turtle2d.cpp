#include "include/turtle/turtle2d.h"

Turtle2D::Turtle2D(const QVector3D& startPosition, const QVector3D& startDirection, const qreal stepLength, const qreal stepAngle):Turtle(startPosition, startDirection, stepLength,stepAngle)
{

}

void Turtle2D::yaw(const qreal angle)
{
    Turtle::yaw(angle);
}

void Turtle2D::pitch(const qreal angle)
{
    //Nothing
}

void Turtle2D::roll(const qreal angle)
{
    //Nothing
}
