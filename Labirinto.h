#ifndef LABIRINTO_H
#define LABIRINTO_H

// Classe que define a interface de um labirinto: o
// metodo virtual deve ser implementado pela
// classe derivada

class Labirinto {
    public:
        virtual bool empty(int x, int y) = 0;   // Retorna true se a posicao x,y estiver livre
        virtual int getWidth()  = 0;            // Retorna largura do labirinto
        virtual int getHeight() = 0;            // Retorna altura do labirinto
};

#endif
