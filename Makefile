SRC=constants.cpp \
Player.cpp \
Puk.cpp \
Renderer.cpp \
Vector.cpp \
World.cpp \
main.cpp
 
OBJ=constants.o \
Player.o \
Puk.o \
Renderer.o \
Vector.o \
World.o \
main.o

PROG = pukGame

FLAGS 				:=
ifeq ($(OS),Windows_NT)
	FLAGS = -L/usr/X11R6/lib -lGL -lGLU -lSDL -lm
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		FLAGS = -lSDL -lGL -lGLU
	endif
	ifeq ($(UNAME_S),Darwin)
		FLAGS = -L/System/Library/Frameworks -framework GLUT -framework OpenGL -I/Library/Frameworks/SDL2.framework/Headers -framework SDL2
	endif
endif

all:
	g++ -c $(SRC) -Wall
	g++ $(OBJ) -o $(PROG) $(FLAGS) -Wall	
