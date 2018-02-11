SRC=constants.cpp \
player.cpp \
puk.cpp \
Renderer.cpp \
vector.cpp \
world.cpp \
main.cpp
 
OBJ=constants.o \
player.o \
puk.o \
Renderer.o \
vector.o \
world.o \
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

$(PROG): $(OBJ)
	g++ $(OBJ) -o $(PROG) $(FLAGS)	

all:
	g++ -c $(SRC)
	g++ $(OBJ) -o $(PROG) $(FLAGS)	
