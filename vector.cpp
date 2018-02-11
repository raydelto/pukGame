/*
 * vector.cpp
 *
 *  Created on: Feb 10, 2018
 *      Author: raydelto
 */
#include "vector.h"

float* t_vector::Modulus(vec *v)
{
	float* length = new float;
	*length = sqrt((v->x * v->x) + (v->z * v->z));
	return length;
}

float* t_vector::Dot(vec *u, vec *v)
{
	float* dot = new float;
	*dot = (u->x * v->x) + (u->z * v->z);
	return dot;
}

vec* t_vector::MultiplyVectorScalar(float s, vec *v)
{
	vec* vect = new vec;
	vect -> x = s * v->x;
	vect -> z = s * v->z;
	return vect;
}

vec* t_vector::Substract(vec *u, vec *v)
{
	vec* vect = new vec;
	vect -> x = u->x - v->x;
	vect-> z = u->z - v->z;
	return vect;
}

vec* t_vector::UnitaryVector(vec *v)
{
	vec* vect = new vec;
	float* length = new float;
	length = Modulus(v);
	vect -> x = v->x / *length;
	vect -> z = v->z / *length;
	return vect;
}
