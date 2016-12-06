all:
	g++ -Wall -fexceptions -O2  -c /media/sf_SharedFolderVM/Study/labproII/ROBO2016/GL.cpp -o ./GL.o
	g++ -Wall -fexceptions -O2  -c /media/sf_SharedFolderVM/Study/labproII/ROBO2016/main.cpp -o ./main.o
	g++ -Wall -fexceptions -O2  -c /media/sf_SharedFolderVM/Study/labproII/ROBO2016/Renderer.cpp -o ./Renderer.o
	g++ -Wall -fexceptions -O2  -c /media/sf_SharedFolderVM/Study/labproII/ROBO2016/Robo.cpp -o ./Robo.o
	g++ -Wall -fexceptions -O2  -c /media/sf_SharedFolderVM/Study/labproII/ROBO2016/main.cpp -o ./main.o
	g++  -o ./projrobo ./GL.o ./main.o ./Renderer.o ./Robo.o  -s  -lGL -lGLU -lglut

