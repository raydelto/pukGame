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

float t_vector::Modulus(vec *v)
{
	float length;
	length = sqrt((v->x * v->x) + (v->z * v->z));
	return length;
}

float t_vector::Dot(vec *u, vec *v)
{
	float dot;
	dot = (u->x * v->x) + (u->z * v->z);
	return dot;
}

vec t_vector::MultiplyVectorScalar(float s, vec *v)
{
	vec vect;
	vect.x = s * v->x;
	vect.z = s * v->z;
	return vect;
}

vec t_vector::Substract(vec *u, vec *v)
{
	vec vect;
	vect.x = u->x - v->x;
	vect.z = u->z - v->z;
	return vect;
}

vec t_vector::UnitaryVector(vec *v)
{
	vec vect;
	float length;
	length = Modulus(v);
	vect.x = v->x / length;
	vect.z = v->z / length;
	return vect;
}
