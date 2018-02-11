#ifndef WORLD_H
#define WORLD_H

#include <stdio.h>
#include <stdlib.h>
#ifdef __APPLE__
	#include <OpenGL/gl.h>
	#include <OpenGl/glu.h>
	#include <GLUT/glut.h>
#else
	#include <GL/gl.h>
	#include <GL/glu.h>
#endif

class World
{
	public:
		void Render(void);
};

#endif
