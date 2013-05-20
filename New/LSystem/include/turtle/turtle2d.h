#ifndef TURTLE2D_H
#define TURTLE2D_H

#include "turtle.h"

class Turtle2D : public Turtle
{
public:
    Turtle2D(const QVector3D& startPosition, const QVector3D& startDirection, const qreal stepLength = DEFAULT_STEP, const qreal stepAngle = DEFAULT_ANGLE);
protected:
    void yaw(const qreal angle);
    void pitch(const qreal angle);
    void roll(const qreal angle);
};

#endif // TURTLE2D_H
