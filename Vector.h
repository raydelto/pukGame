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
} vector;

class Vector
{
	public:
		float* Modulus(vector *v);
		float* Dot(vector *u, vector *v);
		vector* Substract(vector *u, vector *v);
		vector* UnitaryVector(vector *v);
		vector* MultiplyVectorScalar(float s, vector *v);
};
#endif
