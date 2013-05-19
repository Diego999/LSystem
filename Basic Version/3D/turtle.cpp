#include "turtle.h"
#include <QDebug>

Turtle::Turtle()
{
    stepLength = 1.0;
    stepAngle = 90.0; //toRad(90.0);
}

Turtle::Turtle(qreal stepLength, qreal stepAngle)
{
    this->stepLength = stepLength;
    this->stepAngle = stepAngle; //toRad(stepAngle);
}

void Turtle::rotate(qreal angle, QVector3D vec)
{
    QMatrix4x4 matrix;
    matrix.setToIdentity();
    matrix.rotate(angle, vec);
    matrix = matrix.transposed();
    qDebug() << "matrix" << matrix;
    state.setDirection(matrix * state.getDirection());
    qDebug() << "direction" << state.getDirection();
    qDebug() << "result" << matrix * state.getDirection();
}

void Turtle::statePush()
{
    stack.push(state);
}

void Turtle::statePop()
{
    state = stack.pop();
}

QVector3D Turtle::forward()
{
    QVector3D newPosition = state.getPosition() + stepLength * state.getDirection();
    state.setPosition(newPosition);
    return newPosition;
}

void Turtle::yawLeft()
{
    rotate(stepAngle, QVector3D(0.0, 0.0, 1.0));
}

void Turtle::yawRight()
{
    rotate(-stepAngle, QVector3D(0.0, 0.0, 1.0));
}

void Turtle::pitchDown()
{
    rotate(stepAngle, QVector3D(0.0, 1.0, 0.0));
}

void Turtle::pitchUp()
{
    rotate(-stepAngle, QVector3D(0.0, 1.0, 0.0));
}

void Turtle::rollLeft()
{
    rotate(stepAngle, QVector3D(1.0, 0.0, 0.0));
}

void Turtle::rollRight()
{
    rotate(-stepAngle, QVector3D(1.0, 0.0, 0.0));
}

void Turtle::yawAround()
{
    rotate(180.0 /*M_PI*/, QVector3D(0.0, 0.0, 1.0));
}

qreal Turtle::toRad(qreal deg)
{
    /*
     *deg = rad * (180/pi) et rad = deg * ( pi/180)
     */
    return deg * (M_PI/180.0);
}
