/*
 * Renderer.h
 *
 *  Created on: Feb 11, 2018
 *      Author: raydelto
 */

#ifndef RENDERER_H
#define RENDERER_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "constants.cpp"
#include "Player.h"
#include "Puk.h"
#include "Vector.h"
#include "World.h"
#ifdef __APPLE__
	#include <SDL2/SDL.h>
	#include <SDL2/SDL_opengl.h>
	#include <OpenGL/gl.h>
	#include <OpenGl/glu.h>
	#include <GLUT/glut.h>
	#include <GLKit/GLKMatrix4.h>
#else
	#include <GL/gl.h>
	#include <GL/glu.h>
	#include <SDL/SDL.h>
	#include <SDL/SDL_opengl.h>
#endif

class Renderer {
private:
	Puk* _puk;
	World* _world;
	Player* _LPlayer;
	vector* _fVect;
	vector* _normal;
#ifdef __APPLE__
	SDL_Window* _window;
#endif

public:
	Renderer();
	virtual ~Renderer();
	void Init();
	void Display();
	int MainLoop();

};

#endif /* RENDERER_H_ */
