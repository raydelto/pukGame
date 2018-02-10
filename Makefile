SRC=constants.cpp \
player.cpp \
puk.cpp \
renderer.cpp \
vector.cpp \
world.cpp 
 
OBJ=constants.o \
player.o \
puk.o \
renderer.o \
vector.o \
world.o 

FLAGS = -L/System/Library/Frameworks -framework GLUT -framework OpenGL -I/Library/Frameworks/SDL2.framework/Headers -framework SDL2

PROG = pukGame


all:
	g++ -c $(SRC)
	g++ $(OBJ) -o $(PROG) $(FLAGS)	

windows:
	FLAGS = -L/usr/X11R6/lib -lGL -lGLU -lSDL -lm
linux:
	FLAGS = -lSDL -lGL -lGLU
mac:
	
$(PROG): $(OBJ)
	g++ $(OBJ) -o $(PROG) $(FLAGS)	
