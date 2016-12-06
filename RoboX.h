#ifndef ROBOX_H_INCLUDED
#define ROBOX_H_INCLUDED
#include <time.h>
#include <stdlib.h>
#include "Robo.h"

class Robo1 : public Robo {
    public:
    Robo1(int x, int y, Labirinto* lab) : Robo(x, y, lab){};
    void move();
    void draw();
};

class Robo2 : public Robo {
    private:
    int dir;
    public:
    Robo2(int x, int y, Labirinto* lab) : Robo(x, y, lab){dir = 0;}
    void move();
    void draw();
};

class Robo3 : public Robo {
    private:
    int dir;
    public:
    Robo3(int x, int y, Labirinto* lab) : Robo(x, y, lab){dir = 0;}
    void move();
    void draw();
};



void Robo1::move()
{
    int n;

    n = rand()%4;

        switch (n) {
            case 0:
                {if(lab->empty(x+1,y)) x++; break;}
            case 1:
                {if(lab->empty(x-1,y)) x--; break;}
            case 2:
                {if(lab->empty(x,y+1)) y++; break;}
            case 3:
                {if(lab->empty(x,y-1)) y--; break;}
            default: {exit(0);}
        }
}

void Robo2::move()
{
switch (dir) {
    case 0:
    if(lab->empty(x,y+1)) y++;
        else if (!lab->empty(x,y+1))
        {
            if(lab->empty(x-1,y)){x--; dir=3;}
                else if(lab->empty(x+1,y)){x++; dir=1;}
                    else {y--; dir = 2;}
        }
        break;
    case 1:
    if(lab->empty(x+1, y)) x++;
        else if (!lab->empty(x+1,y))
        {
            if(lab->empty(x,y+1)){y++; dir=0;}
                else if(lab->empty(x,y-1)){y--; dir=2;}
                    else {x--; dir=3;}
        }break;
    case 2:
    if(lab->empty(x, y-1)) y--;
        else if (!lab->empty(x,y-1))
        {
            if(lab->empty(x+1,y)){x++; dir=1;}
                else if(lab->empty(x-1,y)){x--; dir=3;}
                    else {y++; dir=0;}
        }break;
    case 3:
    if(lab->empty(x-1, y)) x--;
        else if (!lab->empty(x-1,y))
        {
            if(lab->empty(x,y-1)){y--; dir=2;}
                else if(lab->empty(x,y+1)){y++; dir=0;}
                    else {x++; dir=1;}
        }break;
}
}

void Robo3::move()
{
    switch (dir) {
        case 0:
        if(lab->empty(x+1,y)) {x++; dir=1;}
        else if (!lab->empty(x+1,y))
        {
            if(lab->empty(x,y+1)){y++;}
                else if(lab->empty(x-1,y)){x--; dir=3;}
                    else {y--; dir = 2;}
        } break;
        case 1:
        if(lab->empty(x,y-1)) {y--; dir=2;}
        else if (!lab->empty(x,y-1))
        {
            if(lab->empty(x+1,y)){x++;}
                else if(lab->empty(x,y+1)){y++; dir=0;}
                    else {x--; dir = 3;}
        }break;
        case 2:
        if(lab->empty(x-1,y)) {x--; dir=3;}
        else if (!lab->empty(x-1,y))
        {
            if(lab->empty(x,y-1)){y--;}
                else if(lab->empty(x+1,y)){x++; dir=1;}
                    else {y++; dir = 0;}
        }break;
        case 3:
        if(lab->empty(x,y+1)) {y++; dir=0;}
        else if (!lab->empty(x,y+1))
        {
            if(lab->empty(x-1,y)){x--;}
                else if(lab->empty(x,y-1)){y--; dir=2;}
                    else {x++; dir = 1;}
        }break;
}
}

void Robo1::draw()
{
    float tamX = 1;
    float tamY = 1;

	// Desenha a cabeça do robô
    GL::setColor(255,228,196);	// cabeça/salmao
    GL::fillCirc(0, 0, 0.65);
    GL::setColor(0,191,255);	// olho1,1/azul
    GL::fillCirc(0.25, 0.15, 0.17);
    GL::setColor(0,191,255);	// olho2,1/azul
    GL::fillCirc(-0.25, 0.15, 0.17);
    GL::setColor(0,0,0);	// olho1,2/azul
    GL::fillCirc(0.25, 0.14, 0.05);
    GL::setColor(0,0,0);	// olho2,2/azul
    GL::fillCirc(-0.25, 0.14, 0.05);
    GL::setColor(255,0, 0);	// nariz/vermelho
    GL::fillCirc(0, -0.1, 0.12);

    GL::fillTri(-0.40, 0.45, 0, 0.89, 0.40, 0.45);

    GL::setColor(0,255,0);	// cabelo/azul
    GL::fillCirc(0.70, 0.14, 0.19);
    GL::setColor(0,255,0);	// cabelo/azul
    GL::fillCirc(-0.70, 0.14, 0.19);

    GL::setColor(0,0,0);	// boca/preto
    GL::drawLine(-0.25,-0.32,0.25,-0.33);

}

void Robo2::draw()
{
    float tamX = 1;
    float tamY = 1;

	// Desenha a cabeça do robô
    GL::setColor(0,0,139);	// azul
    GL::fillCirc(0,0.4,0.6);

	// Desenha um retângulo
    GL::setColor(0,0,139);	// azul
    GL::fillRect(-0.6,0.4,0.6,-1);

	// E para finalizar...
    GL::setColor(255, 255, 255);	// branco
    GL::fillCirc(-0.3,0.4,0.2);
    GL::fillCirc( 0.3,0.4,0.2);
}

void Robo3::draw()
{
    float tamX = 1;
    float tamY = 1;

	// Desenha a cabeça do robô
    GL::setColor(240,230,230);	// gelo
    GL::fillCirc(0,0.2,0.6);

    GL::setColor(240,230,230);	// gelo
    GL::fillRect(-0.39,0.2,0.39,-0.8);

    GL::setColor(0,0,0);	// olho
    GL::fillCirc(0.25, 0.15, 0.17);
    GL::setColor(0,0,0);	// olho
    GL::fillCirc(-0.25, 0.15, 0.17);

    GL::fillTri(-0.1, -0.2, 0, 0.02, 0.1, -0.2);

    GL::drawLine(-0.10,-0.4,-0.10,-0.8);
    GL::drawLine(0.10,-0.4,0.10,-0.8);
}




#endif // ROBOX_H_INCLUDED
