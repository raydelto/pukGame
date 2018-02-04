all:
	
windows:
	gcc -o pukGame main.cpp -L/usr/X11R6/lib -lGL -lGLU -lSDL -lm
linux:
	g++ main.cpp -o pukGame -Wall -lSDL -lGL -lGLU
mac:
	g++ main.cpp -o pukGame -Wall -L/System/Library/Frameworks -framework GLUT -framework OpenGL -I/Library/Frameworks/SDL2.framework/Headers -framework SDL2
