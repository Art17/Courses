#include "chessboard_movethread.h"
#include <iostream>

MoveThread::MoveThread()
{
    rect = QRect(0,0,0,0);
    sprite = NULL;
    time = 16;
}

void MoveThread::setRect (QRect rc)
{
    rect = rc;
}
void MoveThread::setSprite (Sprite* sp)
{
    sprite = sp;
}


void MoveThread::run ()
{
    int x1, y1, x2, y2;
    rect.getCoords(&x1, &y1, &x2, &y2);

    double currentX = x1;
    double currentY = y1;

    double deltaX = ((double)(x2 - x1))/time;
    double deltaY =  ((double)(y2 - y1))/time;

    for (int i = 0; i < time; i++)
    {
        currentX += deltaX;
        currentY += deltaY;

        sprite->setPosition(Vector2f(currentX, currentY));

        this->msleep(15);
    }

    emit resultReady(0);
}

