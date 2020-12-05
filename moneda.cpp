#include "moneda.h"

moneda::moneda(int r_, int x, int y)
{
    r = r_;
    posx = x;
    posy = y;
    setPos(posx,posy);
}
int moneda::getR() const
{
    return r;
}

void moneda::setR(int value)
{
    r = value;
}

int moneda::getPosx() const
{
    return posx;
}

void moneda::setPosx(int value)
{
    posx = value;
}

int moneda::getPosy() const
{
    return posy;
}

void moneda::setPosy(int value)
{
    posy = value;
}

QRectF moneda::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);
}

void moneda::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::yellow);
    painter->drawEllipse(boundingRect());

}
