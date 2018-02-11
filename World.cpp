/*
 * world.cpp
 *
 *  Created on: Feb 10, 2018
 *      Author: raydelto
 */
#include "World.h"

void wrl::Render(void)
{
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
		glNormal3f(1.0, 0.0, 0.0);
		glBegin(GL_QUADS);
			glVertex3f(-30.0, -60.0, 0.0);
			glVertex3f(-30.0, 60.0, 0.0);
			glVertex3f(-30.0, 60.0, -10.0);
			glVertex3f(-30.0, -60.0, -10.0);
		glEnd();
	glPopMatrix();

	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
		glNormal3f(-1.0, 0.0, 0.0);
		glBegin(GL_QUADS);
			glVertex3f(30.0, -60.0, 0.0);
			glVertex3f(30.0, 60.0, 0.0);
			glVertex3f(30.0, 60.0, -10.0);
			glVertex3f(30.0, -60.0, -10.0);
		glEnd();
	glPopMatrix();

	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
		glNormal3f(0.0, -1.0, 0.0);
		glBegin(GL_QUADS);
			glVertex3f(-30.0, 60.0, -10.0);
			glVertex3f(30.0, 60.0, -10.0);
			glVertex3f(30.0, 60.0, 0.0);
			glVertex3f(-30.0, 60.0, 0.0);
		glEnd();
	glPopMatrix();

	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
		glNormal3f(0.0, 1.0, 0.0);
		glBegin(GL_QUADS);
			glVertex3f(-30.0, -60.0, -10.0);
			glVertex3f(30.0, -60.0, -10.0);
			glVertex3f(30.0, -60.0, 0.0);
			glVertex3f(-30.0, -60.0, 0.0);
		glEnd();
	glPopMatrix();

	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
		glNormal3f(0.0, 0.0, 1.0);
		glBegin(GL_QUADS);
			glVertex3f(-30.0, -60.0, -10.0);
			glVertex3f(30.0, -60.0, -10.0);
			glVertex3f(30.0, 60.0, -10.0);
			glVertex3f(-30.0, 60.0, -10.0);
		glEnd();
	glPopMatrix();

}
