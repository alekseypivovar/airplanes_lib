#ifndef PLAYERINFO_H
#define PLAYERINFO_H

#include "warships_airplanes_dll_global.h"
#include <QVector>
#include <QString>
#include <QPointF>
#include <QDataStream>
#define FRAMES_PER_SEC 30
#define TILE_SIZE 32
#define PLANE_SPEED 3
#define ANGLE_SPEED 4

struct WARSHIPS_AIRPLANES_DLLSHARED_EXPORT idAndMap {
    qint16 id;
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


    PlayerInfo(qint16 id, QPointF pos, qint16 angle, Type type, quint8 speed, qint8 angleSpeed, quint8 health);
    PlayerInfo();

    qint16  getId() const;
    QPointF  getPos() const;
    qint16   getAngle() const;
    Type     getType() const;
    quint8   getSpeed() const;
    qint8    getAngleSpeed() const;
    quint8   getHealth() const;

    void setId(qint16 id);
    void setPos(QPointF pos);
    void setAngle(qint16 angle);
    void setType(Type type);
    void setSpeed(quint8 speed);
    void setAngleSpeed(qint8 angleSpeed);
    void setHealth(quint8 health);




private:
    qint16 id;
    QPointF pos;
    qint16 angle;
    Type   type;
    quint8 speed;
    qint8  angleSpeed;
    quint8 health;
};

inline QDataStream &operator <<(QDataStream& out, const idAndMap& any)
{
    out << any.id;
    out << /*static_cast<quint32>*/(any.map.size());
    for (auto& vecElement : any.map)
        out << vecElement;

    return out;
}

inline QDataStream &operator >>(QDataStream& out, idAndMap& any)
{
    out >> any.id;
    int/*quint32*/ tempSize;
    out >> tempSize;
    any.map.resize(tempSize);
    for (int/*quint32*/ i = 0 ; i < tempSize ; i++)
        out >> any.map[i];

    return out;
}


inline QDataStream &operator <<(QDataStream& out, const PlayerInfo& any)
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

inline QDataStream &operator >> (QDataStream& out, PlayerInfo& any)
{
    qint16 id;
    out >> id;
    any.setId(id);
    QPointF pos(0,0);
    out >> pos;
    any.setPos(pos);
    qint16 angle;
    out >> angle;
    any.setAngle(angle);
    PlayerInfo::Type type;
    int buffer;
    out >> buffer;
    type = PlayerInfo::Type(buffer);
    any.setType(type);
    quint8 speed;
    out >> speed;
    any.setSpeed(speed);
    qint8 angleSpeed;
    out >> angleSpeed;
    any.setAngleSpeed(angleSpeed);
    quint8 health;
    out >> health;
    any.setHealth(health);
    return out;
}

#endif // PLAYERINFO_H
