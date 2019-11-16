#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsItem>
#include <cmath>
#include <QPainter>
#include "playerinfo.h"
#define BULLET_SIZE 6
class WARSHIPS_AIRPLANES_DLLSHARED_EXPORT BulletInfo
{
    public:
    BulletInfo(QPointF startPos, qint16 angle);
    BulletInfo();

    qint16  angle;
    QPointF startPos;
};


inline QDataStream &operator <<(QDataStream& out, const BulletInfo& any)
{
    out << any.angle;
    out << any.startPos;

    return out;
}

inline QDataStream &operator >>(QDataStream& out, BulletInfo& any)
{
    out >> any.angle;
    out >> any.startPos;

    return out;
}

class WARSHIPS_AIRPLANES_DLLSHARED_EXPORT Bullet : public QGraphicsItem
{
public:
    Bullet(QPointF startPos, qint16 angle);

    virtual void advance(int phase);
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QPointF getStartPos() const;

    BulletInfo getBulletInfo() const;

private:
    quint8  speed;
    qint16  angle;
    QPointF startPos;
};

#endif // BULLET_H
