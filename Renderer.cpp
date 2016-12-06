//
// Classe Renderer: desenha os objetos desejados na tela
// e trata eventos de teclado
//
// APENAS os métodos paint e keyboard podem ser alterados.
//
// O método paint desenha a tela: aqui devem ser usados
// os métodos da classe GL (e SOMENTE aqui).
//
// O método keyboard trata eventos de teclado: o sistema de
// janelas envia a posição atual do mouse (que pode ser ignorada,
// se for o caso) e a tecla pressionada no parâmetro "key".
// Ao final, a tela é redesenhada automaticamente.
//
#include <iostream>
#include "Renderer.h"
#include "GL.h"
#include "Labirinto.h"
#include "Robo.h"

using namespace std;

// Construtor recebe ponteiros para o labirinto e robo,
// para que seja possível desenhá-los
Renderer::Renderer(Labirinto* lab, Robo* robo) {
	this->lab = lab;
    this->robo = robo;
}

// Este método deve desenhar os objetos, usando os métodos
// estáticos da classe GL
//
// Ele é chamado toda vez que a aplicação precisa redesenhar
// a tela gráfica. NÃO DEVE SER CHAMADO MANUALMENTE!
void Renderer::paint() {

	cout << "Renderer::paint" << endl;

    int dimx = lab->getWidth();
    int dimy = lab->getHeight();

    float deltax = 2.0/dimx;
    float deltay = 2.0/dimy;

    GL::setColor(0,0,0);	// cinza claro

	float x,y;
	for(x=-1; x<=1; x+=deltax)
		GL::drawLine(x,-1,x,1);
	for(y=-1; y<=1; y+=deltay)
		GL::drawLine(-1,y,1,y);

    GL::setColor(47,79,79);	// petroleo
	y = -1.0;
	for(int l=0; l<dimy; l++, y+=deltay) {
		x = -1.0;
		for(int c=0; c<dimx; c++, x+=deltax) {
			if(!lab->empty(c,dimy-l-1))
				GL::fillRect(x,y,x+deltax,y+deltay);
		}
	}

    glPushMatrix();
    glTranslatef(-1+deltax/2,1-deltay/2,0);
    int rx = robo->getX();
    int ry = robo->getY();
    glTranslatef(rx*deltax, -ry*deltay, 0);
    glScalef(deltax/2,deltay/2,1);
    robo->draw();
    glPopMatrix();
}


void Renderer::keyboard(unsigned char key, int x, int y) {
	cout << "Renderer::keyboard: " << key << endl;
    if(robo->exited()) exit(1);
        else robo->move();
}

