/*
 * vector.cpp
 *
 *  Created on: Feb 10, 2018
 *      Author: raydelto
 */
#include "Vector.h"

float* Vector::Modulus(vector *v)
{
	float* length = new float;
	*length = sqrt((v->x * v->x) + (v->z * v->z));
	return length;
}

float* Vector::Dot(vector *u, vector *v)
{
	float* dot = new float;
	*dot = (u->x * v->x) + (u->z * v->z);
	return dot;
}

vector* Vector::MultiplyVectorScalar(float s, vector *v)
{
	vector* vect = new vector;
	vect -> x = s * v->x;
	vect -> z = s * v->z;
	return vect;
}

vector* Vector::Substract(vector *u, vector *v)
{
	vector* vect = new vector;
	vect -> x = u->x - v->x;
	vect-> z = u->z - v->z;
	return vect;
}

vector* Vector::UnitaryVector(vector *v)
{
	vector* vect = new vector;
	float* length = new float;
	length = Modulus(v);
	vect -> x = v->x / *length;
	vect -> z = v->z / *length;
	return vect;
}
