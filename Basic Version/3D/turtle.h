#ifndef TURTLE_H
#define TURTLE_H

#include <QtCore>
#include <QMatrix4x4>
#include "state.h"

class Turtle
{
private:
    void            rotate(qreal angle, QVector3D vec);
    QMatrix4x4      tranformMatrix;
    QStack<State>   stack;
    qreal           stepLength;
    qreal           stepAngle;

public:
    State           state;
    Turtle();
    Turtle(qreal stepLength, qreal stepAngle);
    void            statePush();
    void            statePop();
    QVector3D       forward();
    void            beginTranform();
    void            endTransform();
    void            yawLeft();
    void            yawRight();
    void            yawAround();
    void            pitchDown();
    void            pitchUp();
    void            rollLeft();
    void            rollRight();
    qreal           toRad(qreal deg);
};

#endif // TURTLE_H
