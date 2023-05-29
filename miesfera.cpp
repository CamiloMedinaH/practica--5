#include "miesfera.h"

miesfera::miesfera()
{
    vy=7;
}

QRectF miesfera::boundingRect() const
{
    return QRectF(-10,-10,7,7);
}

void miesfera::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::darkBlue);
    painter->drawEllipse(boundingRect());
    //QPixmap pixmap;
    //pixmap.load(":/Imagenes/pokebola.png");
    //painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

void miesfera::mover()
{
    setPos(x(),y()+vy);
}

void miesfera::choque()
{
    vy=-vy/1.3;
}
