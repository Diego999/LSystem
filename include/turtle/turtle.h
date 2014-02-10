#ifndef TURTLE_H
#define TURTLE_H

#include "state.h"
#include "include/config.h"

#include <QStack>

class Turtle
{
public:
    Turtle(const qreal stepLength, const qreal stepAngle);

    void reinitialize();

    void turnLeft();
    void turnRight();
    void pitchDown();
    void pitchUp();
    void rollLeft();
    void rollRight();
    void turnAround();

    void statePush();
    void statePop();

    void forward();

    QVector3D getOldPosition() const {return oldPosition;}
    QVector3D getPosition() const {return position;}

private:
    void turn(const qreal angle);
    void pitch(const qreal angle);
    void roll(const qreal angle);

    QVector3D vecH;
    QVector3D vecL;
    QVector3D vecU;

    QVector3D oldPosition;
    QVector3D position;

    QStack<State> stack;
    State state;
    qreal stepLength;
    qreal stepAngle;
};

#endif // TURTLE_H
