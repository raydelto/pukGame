all:
	gcc -o pukGame main.cpp -L/usr/X11R6/lib -lGL -lGLU -lSDL -lm
linux:
	g++ main.cpp -o pukGame -Wall -lSDL -lGL -lGLU
