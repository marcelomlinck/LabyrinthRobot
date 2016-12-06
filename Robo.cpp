#include "GL.h"
#include "Robo.h"
#include "Labirinto.h"

Robo::Robo(int x, int y, Labirinto* lab)
{
    this->x = x;
    this->y = y;
    this->lab = lab;
}

bool Robo::exited()
{
    if(y >= lab->getHeight() || x >= lab->getWidth())
    return true;
    else
    return false;
}





