#ifndef PLANE_H
#define PLANE_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <cmath>
#include <QGraphicsScene>
#include "playerinfo.h"
#include "bullet.h"
#define IMAGE_SIZE 64

class WARSHIPS_AIRPLANES_DLLSHARED_EXPORT Plane : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Plane(qint16 id, PlayerInfo::Type type, qint16 angle, quint8 speed, qint8 angleSpeed, quint8 health);
    enum { Type = UserType + 1 };
    void setSpeed(quint8 speed);
    void setAngleSpeed(qint8 angleSpeed);
    void setHealth(quint8 health);
    void setAngle(qint16  angle);


    PlayerInfo::Type    getObjectType() const;
    qint16   getAngle() const;
    quint8   getSpeed() const;
    qint8    getAngleSpeed() const;
    quint8   getHealth() const;
    qint16   getId() const;
    QPointF  getGunPos() const;
    int type() const;

    virtual void advance(int phase);
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    qint16 id;
    PlayerInfo::Type objectType;
    quint8  speed;
    qint8   angleSpeed;
    quint8  health;
    qint16  angle;

    void checkCollisions();

signals:
    void planeMoved(Plane* plane);
    void planeAndBulletCollided(Plane* plane, Bullet* bullet);

};

#endif // PLANE_H
