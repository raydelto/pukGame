SRC=constants.cpp \
Player.cpp \
Puk.cpp \
Renderer.cpp \
Vector.cpp \
World.cpp \
glad.c \
main.cpp
 
OBJ=constants.o \
Player.o \
Puk.o \
Renderer.o \
Vector.o \
World.o \
glad.o \
main.o

PROG = pukGame

FLAGS 				:=
ifeq ($(OS),Windows_NT)
	LIBS = -L/usr/X11R6/lib -lGL -lGLU -lSDL -lm
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		LIBS = -lSDL -lGL -lGLU
	endif
	ifeq ($(UNAME_S),Darwin)
		LIBS= -L/opt/homebrew/opt/sdl2/lib \
			-lsdl2 -framework OpenGL

		INCLUDES=-I/opt/homebrew/opt/sdl2/include \
				-I./include \
				-I/usr/local/include
	endif
endif

WARNINGS = -w

all:
	clang++ -c -g $(SRC) $(INCLUDES) $(WARNINGS)
	clang++ -g $(OBJ) -o $(PROG) $(LIBS) $(INCLUDES) $(WARNINGS)
