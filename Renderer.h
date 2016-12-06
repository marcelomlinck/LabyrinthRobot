#ifndef RENDERER_H
#define RENDERER_H

class Labirinto;
class Robo;

class Renderer {
	public:
		Renderer(Labirinto* lab, Robo* robo);
		virtual void paint();
		virtual void keyboard(unsigned char key, int x, int y);
	protected:
		Labirinto* lab;
		Robo* robo;
};

#endif
