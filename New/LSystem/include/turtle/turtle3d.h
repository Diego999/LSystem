#ifndef TURTLE3D_H
#define TURTLE3D_H

#include "turtle.h"

class Turtle3D : public Turtle
{
public:
    Turtle3D(const QVector3D& startPosition, const QVector3D& startDirection, const qreal stepLength = DEFAULT_STEP, const qreal stepAngle = DEFAULT_ANGLE);

protected:
    void yaw(const qreal angle);
    void pitch(const qreal angle);
    void roll(const qreal angle);
};

#endif // TURTLE3D_H
