#ifndef PLAYERINFO_H
#define PLAYERINFO_H

#include "warships_airplanes_dll_global.h"
#include <QVector>
#include <QString>
#include <QPointF>
#include <QDataStream>
#define FRAMES_PER_SEC 40
#define TILE_SIZE 32
#define PLANE_SPEED 5
#define ANGLE_SPEED 1

struct idAndMap {
    qint32 id;
    QVector <QString> map;
};



class WARSHIPS_AIRPLANES_DLLSHARED_EXPORT PlayerInfo
{

public:
    enum Type {
        SHIP,
        PLANE,
        UNDEFINED
    };


    PlayerInfo(qint32 id, QPointF pos, qreal angle, Type type, qreal speed, qreal angleSpeed, qint16 health);
    PlayerInfo();

    qint32  getId() const;
    QPointF getPos() const;
    qreal   getAngle() const;
    Type    getType() const;
    qreal   getSpeed() const;
    qreal   getAngleSpeed() const;
    qint16  getHealth() const;

    void setId(qint32 id);
    void setPos(QPointF pos);
    void setAngle(qreal angle);
    void setType(Type type);
    void setSpeed(qreal speed);
    void setAngleSpeed(qreal angleSpeed);
    void setHealth(qint16 health);




private:
    qint32 id;
    QPointF pos;
    qreal angle;
    Type type;
    qreal speed;
    qreal angleSpeed;
    qint16 health;
};

inline QDataStream &operator <<(QDataStream &out, const idAndMap &any)
{
    out << any.id;
    out << any.map;
    return out;
}

inline QDataStream &operator >>(QDataStream &out, idAndMap &any)
{
    out >> any.id;
    out >> any.map;
    return out;
}


inline QDataStream &operator <<(QDataStream &out, const PlayerInfo &any)
{
    out << any.getId();
    out << any.getPos();
    out << any.getAngle();
    out << any.getType();
    out << any.getSpeed();
    out << any.getAngleSpeed();
    out << any.getHealth();
    return out;
}

inline QDataStream &operator >> (QDataStream &out, PlayerInfo &any)
{
    qint32 id;
    out >> id;
    any.setId(id);
    QPointF pos(0,0);
    out >> pos;
    any.setPos(pos);
    qreal angle;
    out >> angle;
    any.setAngle(angle);
    PlayerInfo::Type type;
    int buffer;
    out >> buffer;
    type = PlayerInfo::Type(buffer);
    any.setType(type);
    qreal speed;
    out >> speed;
    any.setSpeed(speed);
    qreal angleSpeed;
    out >> angleSpeed;
    any.setAngleSpeed(angleSpeed);
    qint16 health;
    out >> health;
    any.setHealth(health);
    return out;
}

#endif // PLAYERINFO_H
