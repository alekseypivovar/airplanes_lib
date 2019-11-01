#ifndef UNIT_H
#define UNIT_H
#include <QObject>
#include <QGraphicsItem>
#include "playerinfo.h"

class Unit : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Unit();

private:

};

#endif // UNIT_H
