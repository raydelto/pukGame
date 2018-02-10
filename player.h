#ifndef PLAYER_H
#define PLAYER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "vector.h"

#ifdef __APPLE__
	#include <OpenGL/gl.h>
	#include <OpenGl/glu.h>
	#include <GLUT/glut.h>
#else
	#include <GL/gl.h>
	#include <GL/glu.h>
#endif

class CPlayer
{
	public:
		vec pos;
		vec vel;
		void Render(void);
};
#endif
