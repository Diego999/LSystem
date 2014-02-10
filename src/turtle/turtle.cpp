#include "include/turtle/turtle.h"
#include <cmath>

Turtle::Turtle(const qreal _stepLength, const qreal _stepAngle):
    vecH(_stepLength,0,0), vecL(0,_stepLength,0), vecU(0,0,_stepLength), oldPosition(0,0,0),position(0,0,0), stepLength(_stepLength), stepAngle(_stepAngle/180.0*M_PI)
{

}

void Turtle::reinitialize()
{
    oldPosition.setX(0);
    oldPosition.setY(0);
    oldPosition.setZ(0);

    position.setX(0);
    position.setY(0);
    position.setZ(0);
}

void Turtle::forward()
{
    oldPosition.setX(position.x());
    oldPosition.setY(position.y());
    oldPosition.setZ(position.z());

    position += vecU;
    position += vecH;
    position += vecL;

    /*qDebug() << "H:" << vecH;
    qDebug() << "L:" << vecL;
    qDebug() << "U:" << vecU;

    qDebug() << "--------------";*/

}

void Turtle::turnLeft()
{
    turn(stepAngle);
}

void Turtle::turnRight()
{
    turn(-stepAngle);
}

void Turtle::turnAround()
{
    turn(M_PI);
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
    roll(stepAngle);
}

void Turtle::rollRight()
{
    roll(-stepAngle);
}

void Turtle::turn(const qreal angle)
{
    QVector3D vecHNew(0,0,0);
    vecHNew.setX(vecH.x()*cos(angle)-vecL.x()*sin(angle));
    vecHNew.setY(vecH.y()*cos(angle)-vecL.y()*sin(angle));
    vecHNew.setZ(vecH.z()*cos(angle)-vecL.z()*sin(angle));

    vecL.setX(vecL.x()*cos(angle)+vecH.x()*sin(angle));
    vecL.setY(vecL.y()*cos(angle)+vecH.y()*sin(angle));
    vecL.setZ(vecL.z()*cos(angle)+vecH.z()*sin(angle));

    vecH = vecHNew;
}

void Turtle::pitch(const qreal angle)
{
    QVector3D vecHNew(0,0,0);
    vecHNew.setX(vecH.x()*cos(angle)+vecU.x()*sin(angle));
    vecHNew.setY(vecH.y()*cos(angle)+vecU.y()*sin(angle));
    vecHNew.setZ(vecH.z()*cos(angle)+vecU.z()*sin(angle));

    vecU.setX(vecU.x()*cos(angle)-vecH.x()*sin(angle));
    vecU.setY(vecU.y()*cos(angle)-vecH.y()*sin(angle));
    vecU.setZ(vecU.z()*cos(angle)-vecH.z()*sin(angle));
    vecH = vecHNew;
}

void Turtle::roll(const qreal angle)
{
    QVector3D vecLNew(0,0,0);
    vecLNew.setX(vecL.x()*cos(angle)+vecU.x()*sin(angle));
    vecLNew.setY(vecL.y()*cos(angle)+vecU.y()*sin(angle));
    vecLNew.setZ(vecL.z()*cos(angle)+vecU.z()*sin(angle));

    vecU.setX(vecU.x()*cos(angle)-vecL.x()*sin(angle));
    vecU.setY(vecU.y()*cos(angle)-vecL.y()*sin(angle));
    vecU.setZ(vecU.z()*cos(angle)-vecL.z()*sin(angle));

    vecL = vecLNew;
}

