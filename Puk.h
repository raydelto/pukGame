#ifndef PUK_H
#define PUK_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "Vector.h"

#ifdef __APPLE__
	#include <OpenGL/gl.h>
	#include <OpenGl/glu.h>
	#include <GLUT/glut.h>
#else
	#include <GL/gl.h>
	#include <GL/glu.h>
#endif

class Puk
{
	public:
		vector vel;
		vector pos;
		vector frict;
		float radius;
		vector* CalcResponse(vector *normal);
		void Render(void);

};
#endif
