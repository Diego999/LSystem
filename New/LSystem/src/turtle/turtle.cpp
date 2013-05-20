#include "include/turtle/turtle.h"

Turtle::Turtle(const QVector3D& startPosition, const QVector3D &startDirection, const qreal stepLength, const qreal stepAngle):state(startPosition, startDirection), stepLength(stepLength),stepAngle(stepAngle)
{
    reinitialize();
}

Turtle::~Turtle()
{

}

void Turtle::reinitialize()
{
    state.setDefaultPositionAndDirection();
}

QVector3D Turtle::forward()
{
    state.forward(stepLength);
    return getPosition();
}

void Turtle::beginTranform()
{
    transformMatrix.setToIdentity();
}

void Turtle::endTransform()
{
    state.setDirection(transformMatrix);
    beginTranform();
}

QVector3D Turtle::getOldPosition() const
{
    return state.getOldPosition();
}

QVector3D Turtle::getPosition() const
{
    return state.getPosition();
}

QVector3D Turtle::getDirection() const
{
    return state.getDirection();
}

void Turtle::yawLeft()
{
    yaw(stepAngle);
}

void Turtle::yawRight()
{
    yaw(-stepAngle);
}

void Turtle::yawAround()
{
    yaw(180.0);
}

void Turtle::pitchDown()
{
    pitch(stepAngle);
}

void Turtle::pitchUp()
{
    pitch(-stepAngle);
}

void Turtle::rollLeft()
{
    roll(-stepAngle);
}

void Turtle::rollRight()
{
    roll(stepAngle);
}

void Turtle::rotate(const qreal angle, const QVector3D &vec)
{
    QMatrix4x4 matrix;
    matrix.setToIdentity();
    matrix.rotate(angle,vec);
    transformMatrix *= matrix;
}

void Turtle::yaw(const qreal angle)
{
    rotate(angle, QVector3D(0.0, 0.0, 1.0));
}

void Turtle::pitch(const qreal angle)
{
    rotate(angle, QVector3D(0.0, 1.0, 0.0));
}

void Turtle::roll(const qreal angle)
{
    rotate(angle, QVector3D(1.0, 0.0, 0.0));
}

void Turtle::statePush()
{
    stack.push(state);
}

void Turtle::statePop()
{
    state = stack.pop();
}
