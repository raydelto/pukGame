/*
 * Renderer.h
 *
 *  Created on: Feb 11, 2018
 *      Author: raydelto
 */

#ifndef RENDERER_H
#define RENDERER_H
#include "vector.h"
#include "puk.h"
#include "world.h"
#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "constants.cpp"
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
	pukk* _puk;
	wrl* _world;
	CPlayer* _LPlayer;
	vec* _fVect;
	vec* _normal;
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
