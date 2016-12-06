#include "GL.h"
#include "Renderer.h"
#include <iostream>
#include <string>
#include "Labaux.h"
#include "RoboX.h"
#include <time.h>

using namespace std;

int main(int argc, char *argv[])
{
	srand(time(NULL));
	if(argc==1) {
		cout << "please use " << argc << " labirinto.txt" << endl;
		exit(0);
	}
    ifstream arq;
    string linha, str;
    char matriz[200][200];
    int x,y,roboT, xp, yp, i = 0, j;
    arq.open(argv[1], ios::in);
    if(!arq.is_open())
    {
        cout << "ERRO CATASTROFICO!" << endl;
        return 0;
    }

    arq >> str >> x >> y;
    arq >> str >> roboT;
    arq >> str >> xp >> yp;
    while(arq.good()){
        getline(arq,linha);
        for(j=0; j<=y-1; j++){
            cout << linha[j];
            matriz[i][j] = linha[j];
        }
        cout << endl;
        i++;
    }

    if(arq.bad() || !arq.eof())
    {
        cout << "ERRO GRAVISSIMO!" << endl;
        return 0;
    }

    Labirinto * labirinto = new Labaux(matriz, y, x);

    Robo * robo;

    switch (roboT) {
        case 1: { robo = new Robo1(xp, yp, labirinto); cout << "teste1" << endl; break; }
        case 2: { robo = new Robo2(xp, yp, labirinto); cout << "teste2" << endl; break; }
        case 3: { robo = new Robo3(xp, yp, labirinto); cout << "teste3" << endl; break; }
        default: return 0;
    }

    arq.close();

    Renderer renderer(labirinto, robo);

    GL::init("TRABALHO DA STRONDA! :D", &renderer);

	GL::loop();
}
