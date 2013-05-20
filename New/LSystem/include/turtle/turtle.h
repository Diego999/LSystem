#ifndef TURTLE_H
#define TURTLE_H

#include "state.h"
#include "include/config.h"

#include <QMatrix4x4>
#include <QStack>

class Turtle
{
public:
    Turtle(const QVector3D& startPosition, const QVector3D& startDirection, const qreal stepLength = DEFAULT_STEP, const qreal stepAngle = DEFAULT_ANGLE);
    virtual ~Turtle();

    QVector3D forward();
    void beginTranform();
    void endTransform();
    void reinitialize();

    QVector3D getOldPosition() const;
    QVector3D getPosition() const;
    QVector3D getDirection() const;

    void yawLeft();
    void yawRight();
    void yawAround();
    void pitchDown();
    void pitchUp();
    void rollLeft();
    void rollRight();

    void statePush();
    void statePop();

protected:
    virtual void yaw(const qreal angle) = 0;
    virtual void pitch(const qreal angle) = 0;
    virtual void roll(const qreal angle) = 0;

    void rotate(const qreal angle, const QVector3D& vec);

    QMatrix4x4 transformMatrix;
    QStack<State> stack;
    State state;
    qreal stepLength;
    qreal stepAngle;
};

#endif // TURTLE_H
