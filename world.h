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

class wrl
{
	public:
		void Render(void);
};

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
