all:
	gcc -o pukGame main.cpp -L/usr/X11R6/lib -lGL -lGLU -lSDL -lm
