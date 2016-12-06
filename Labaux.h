#ifndef LABAUX_H_INCLUDED
#define LABAUX_H_INCLUDED
#include "Labirinto.h"
#include <iostream>
using namespace std;

class Labaux : public Labirinto {
    private:
    char mat[200][200];
    int width;
    int height;

    public:
    int getHeight();
    int getWidth();
    bool empty(int x, int y);
    Labaux(char mat1[200][200], int w, int h);
};


Labaux::Labaux(char mat1[200][200], int w, int h)
{
    height = h;
    width = w;
    for(int i=0; i <= h; i++)
    {
        for(int j=0; j <= w; j++)
        {
            mat[j][i] = mat1[i+1][j];
        }
    }
}

int Labaux::getHeight()
{
    return height;
}

int Labaux::getWidth()
{
    return width;
}

bool Labaux::empty(int x, int y)
{
    if(mat[x][y] == '*') return false;
    else return true;
}






#endif // LABAUX_H_INCLUDED
