#include "plane.h"

Plane::Plane(qint16 id, PlayerInfo::Type type, qint16 angle, quint8 speed, qint8 angleSpeed, quint8 health)
{
    this->id     = id;
    this->objectType   = type;
    this->speed  = speed;
    this->angleSpeed = angleSpeed;
    this->health = health;
    this->angle  = angle;
}

void Plane::setSpeed(quint8 speed)
{
    this->speed = speed;
}

void Plane::setAngleSpeed(qint8 angleSpeed)
{
    this->angleSpeed = angleSpeed;
}

void Plane::setHealth(quint8 health)
{
    this->health = health;
}

void Plane::setAngle(qint16 angle)
{
    this->angle = angle;
}

PlayerInfo::Type Plane::getObjectType() const
{
    return objectType;
}

qint16 Plane::getAngle() const
{
    return angle;
}

quint8 Plane::getSpeed() const
{
    return speed;
}


qint8 Plane::getAngleSpeed() const
{
    return  angleSpeed;
}

quint8 Plane::getHealth() const
{
    return health;
}

qint16 Plane::getId() const
{
    return id;
}

QPointF Plane::getGunPos() const
{
    qreal x = (IMAGE_SIZE / 2) * cos(angle * M_PI / 180.0) * ( 1);
    qreal y = (IMAGE_SIZE / 2) * sin(angle * M_PI / 180.0) * (-1);
    return QPointF(x, y);
}

int Plane::type() const
{
    return Type;
}

void Plane::advance(int phase)
{
    if (phase) {
        angle += angleSpeed;
        if (angle > 360)
            angle -= 360;
        else if (angle < 0)
            angle += 360;
        qreal dx = speed * cos(angle * M_PI / 180.0) * ( 1);
        qreal dy = speed * sin(angle * M_PI / 180.0) * (-1);
        this->moveBy(dx, dy);
        this->setRotation(-angle);
        checkCollisions();
        emit planeMoved(this);
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
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->save();
    painter->drawPixmap(- IMAGE_SIZE / 2, - IMAGE_SIZE / 2, IMAGE_SIZE, IMAGE_SIZE, QPixmap(":/images/plane.png"));
    painter->restore();
}

void Plane::checkCollisions()
{
    QList<QGraphicsItem *> items = collidingItems();
    if (items.isEmpty()) {
        return;
    }

    for (int i = 0; i < items.length(); i++) {
        Bullet* bullet = qgraphicsitem_cast<Bullet*>(items.at(i));
        Plane* plane = qgraphicsitem_cast<Plane*>(items.at(i));
        if (bullet) {
            emit planeAndBulletCollided(this, bullet);
        }
        if (plane) {
            emit planeAndPlaneCollided(this, plane);
        }
    }
}


