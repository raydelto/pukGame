/*
 * puk.cpp
 *
 *  Created on: Feb 10, 2018
 *      Author: raydelto
 */
#include "Puk.h"

vector* Puk::CalcResponse(vector *normal)
{
	float t_dot;
	float mod;
	vector unit;
	vector* response = new vector();
	Vector vector;
	unit = *vector.UnitaryVector(&vel);
	t_dot = *vector.Dot(&unit, normal);
	response = vector.MultiplyVectorScalar(2 * t_dot, normal);
	response = vector.Substract(&unit, response);
	mod = *vector.Modulus(&vel);
	response = vector.MultiplyVectorScalar(mod, response);

	return response;
}

void Puk::Render(void)
{
	glColor3f(1.0, 0.0, 0.0);
	glPushMatrix();
		glTranslatef(pos.x, pos.z, 0.0);
		glBegin(GL_QUADS);
			glVertex3f(-1.0, -1.0, -5.0);
			glVertex3f(-1.0, 1.0, -5.0);
			glVertex3f(1.0, 1.0, -5.0);
			glVertex3f(1.0, -1.0, -5.0);
		glEnd();
	glPopMatrix();
}
