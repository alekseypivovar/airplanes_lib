#include "plane.h"

Plane::Plane(qint32 id, PlayerInfo::Type type, qreal angle, qreal speed, qreal angleSpeed, qint16 health)
{
    this->id     = id;
    this->type   = type;
    this->speed  = speed;
    this->angleSpeed = angleSpeed;
    this->health = health;
    this->angle  = angle;
}

void Plane::setSpeed(qreal speed)
{
    this->speed = speed;
}

void Plane::setAngleSpeed(qreal angleSpeed)
{
    this->angleSpeed = angleSpeed;
}

void Plane::setHealth(qint16 health)
{
    this->health = health;
}

PlayerInfo::Type Plane::getType() const
{
    return type;
}

qreal Plane::getSpeed() const
{
    return speed;
}


qreal Plane::getAngleSpeed() const
{
    return  angleSpeed;
}

qint16 Plane::getHealth() const
{
    return health;
}

qint32 Plane::getId() const
{
    return id;
}

void Plane::advance(int phase)
{
    if (phase) {
        angle += angleSpeed;
        qreal dx = speed * cos(angle * M_PI / 180.0) * ( 1);
        qreal dy = speed * sin(angle * M_PI / 180.0) * (-1);
        this->moveBy(dx, dy);
        this->setRotation(-angle);
    }
}

QRectF Plane::boundingRect() const
{
    QPointF ptPosition(- IMAGE_SIZE / 2, - IMAGE_SIZE / 2);
    QSizeF  size(IMAGE_SIZE, IMAGE_SIZE);
    return  QRectF(ptPosition, size);
}

void Plane::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->save();
    painter->drawPixmap(- IMAGE_SIZE / 2, - IMAGE_SIZE / 2, IMAGE_SIZE, IMAGE_SIZE, QPixmap(":/images/plane.png"));
    painter->restore();
}
