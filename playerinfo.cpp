#include "playerinfo.h"

PlayerInfo::PlayerInfo(qint16 id, QPointF pos, qint16 angle, Type type, quint8 speed, qint8 angleSpeed, quint8 health)
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

qint16 PlayerInfo::getId() const
{
    return id;
}

QPointF PlayerInfo::getPos() const
{
    return pos;
}

qint16 PlayerInfo::getAngle() const
{
    return angle;
}

PlayerInfo::Type PlayerInfo::getType() const
{
    return  type;
}

quint8 PlayerInfo::getSpeed() const
{
    return speed;
}


qint8 PlayerInfo::getAngleSpeed() const
{
    return angleSpeed;
}

quint8 PlayerInfo::getHealth() const
{
    return health;
}

void PlayerInfo::setId(qint16 id)
{
    this->id = id;
}

void PlayerInfo::setPos(QPointF pos)
{
    this->pos = pos;
}

void PlayerInfo::setAngle(qint16 angle)
{
    this->angle = angle;
}

void PlayerInfo::setType(PlayerInfo::Type type)
{
    this->type = type;
}

void PlayerInfo::setSpeed(quint8 speed)
{
    this->speed = speed;
}

void PlayerInfo::setAngleSpeed(qint8 angleSpeed)
{
    this->angleSpeed = angleSpeed;
}

void PlayerInfo::setHealth(quint8 health)
{
    this->health = health;
}
