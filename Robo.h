#ifndef ROBO_H
#define ROBO_H


class Labirinto;

class Robo {
    public:
        Robo(int x, int y, Labirinto* lab);  // Construtor: recebe posição inicial
        virtual void draw() = 0;             // Desenha robo
        virtual bool exited();               // Retorna true se robo saiu do labirinto
        virtual void move() = 0;             // Método que avança o robô para a próxima posição
        int getX() { return x; }             // Obtem posicao atual do robo (x)
        int getY() { return y; }             // Obtem posicao atual do robo (y)
    protected:
        int x;
        int y;
        Labirinto* lab;
};

#endif
