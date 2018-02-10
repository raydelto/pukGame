#ifndef VECTOR_H
#define VECTOR_H

#include <math.h>
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

typedef struct
{
	float x, z;
}vec;

class t_vector
{
	public:
		float Modulus(vec *v);
		float Dot(vec *u, vec *v);
		vec Substract(vec *u, vec *v);
		vec UnitaryVector(vec *v);
		vec MultiplyVectorScalar(float s, vec *v);
};
#endif
