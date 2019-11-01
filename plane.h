#ifndef PLANE_H
#define PLANE_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <cmath>
#include "playerinfo.h"
#define IMAGE_SIZE 64

class WARSHIPS_AIRPLANES_DLLSHARED_EXPORT Plane : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Plane(qint32 id, PlayerInfo::Type type, qreal angle, qreal speed, qreal angleSpeed, qint16 health);
    void setSpeed(qreal speed);
    void setAngleSpeed(qreal angleSpeed);
    void setHealth(qint16 health);

    PlayerInfo::Type    getType() const;
    qreal   getSpeed() const;
    qreal   getAngleSpeed() const;
    qint16  getHealth() const;
    qint32  getId() const;

    virtual void advance(int phase);
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    qint32 id;
    PlayerInfo::Type type;
    qreal  speed;
    qreal  angleSpeed;
    qint16 health;
    qreal  angle;

};

#endif // PLANE_H
