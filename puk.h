#ifndef PUK_H
#define PUK_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

#ifdef __APPLE__
	#include <OpenGL/gl.h>
	#include <OpenGl/glu.h>
	#include <GLUT/glut.h>
#else
	#include <GL/gl.h>
	#include <GL/glu.h>
#endif

class pukk
{
	public:
		vec vel;
		vec pos;
		vec frict;
		float radius;
		vec CalcResponse(vec *normal);
		void Render(void);

};
#endif
