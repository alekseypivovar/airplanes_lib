#include "bullet.h"

Bullet::Bullet(QPointF startPos, qint16 angle)
{
    this->startPos = startPos;
    this->angle = angle;
    speed = PLANE_SPEED * 4;
}

void Bullet::advance(int phase)
{
    if (phase) {
        qreal dx = speed * cos(angle * M_PI / 180.0) * ( 1);
        qreal dy = speed * sin(angle * M_PI / 180.0) * (-1);
        this->moveBy(dx, dy);
    }
}

QRectF Bullet::boundingRect() const
{
    QPointF ptPosition(- BULLET_SIZE / 2, - BULLET_SIZE / 2);
    QSizeF  size(BULLET_SIZE, BULLET_SIZE);
    return  QRectF(ptPosition, size);
}

void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->save();
    painter->setPen(QPen(Qt::darkYellow));
    painter->setBrush(QBrush(Qt::darkYellow));
    painter->drawRect(boundingRect());
    painter->restore();
}

QPointF Bullet::getStartPos() const
{
    return startPos;
}

BulletInfo Bullet::getBulletInfo() const
{
    return BulletInfo(startPos, angle);
}

BulletInfo::BulletInfo(QPointF startPos, qint16 angle)
{
    this->startPos = startPos;
    this->angle = angle;
}

BulletInfo::BulletInfo()
{
}

