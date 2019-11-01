#include "playerinfo.h"

PlayerInfo::PlayerInfo(qint32 id, QPointF pos, qreal angle, Type type, qreal speed, qreal angleSpeed, qint16 health)
{
    this->id         = id;
    this->pos        = pos;
    this->angle      = angle;
    this->type       = type;
    this->speed      = speed;
    this->angleSpeed = angleSpeed;
    this->health     = health;
}

PlayerInfo::PlayerInfo()
{
    this->id    = -1;
    this->pos   = QPointF(0, 0);
    this->angle = 0;
    this->type  = UNDEFINED;
    this->speed      = 0;
    this->angleSpeed = 0;
}

qint32 PlayerInfo::getId() const
{
    return id;
}

QPointF PlayerInfo::getPos() const
{
    return pos;
}

qreal PlayerInfo::getAngle() const
{
    return angle;
}

PlayerInfo::Type PlayerInfo::getType() const
{
    return  type;
}

qreal PlayerInfo::getSpeed() const
{
    return speed;
}


qreal PlayerInfo::getAngleSpeed() const
{
    return angleSpeed;
}

qint16 PlayerInfo::getHealth() const
{
    return health;
}

void PlayerInfo::setId(qint32 id)
{
    this->id = id;
}

void PlayerInfo::setPos(QPointF pos)
{
    this->pos = pos;
}

void PlayerInfo::setAngle(qreal angle)
{
    this->angle = angle;
}

void PlayerInfo::setType(PlayerInfo::Type type)
{
    this->type = type;
}

void PlayerInfo::setSpeed(qreal speed)
{
    this->speed = speed;
}

void PlayerInfo::setAngleSpeed(qreal angleSpeed)
{
    this->angleSpeed = angleSpeed;
}

void PlayerInfo::setHealth(qint16 health)
{
    this->health = health;
}
