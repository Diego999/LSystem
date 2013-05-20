#include "include/turtle/turtle3d.h"

Turtle3D::Turtle3D(const QVector3D& startPosition, const QVector3D& startDirection, const qreal stepLength, const qreal stepAngle):Turtle(startPosition, startDirection, stepLength,stepAngle)
{

}

void Turtle3D::yaw(const qreal angle)
{
    Turtle::yaw(angle);
}

void Turtle3D::pitch(const qreal angle)
{
    Turtle::pitch(angle);
}

void Turtle3D::roll(const qreal angle)
{
    Turtle::roll(angle);
}
