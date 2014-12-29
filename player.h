#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>

class CPlayer
{
	public:
		vec pos;
		vec vel;
		void Render(void);
};

void CPlayer::Render(void)
{
	glColor3f(0.0, 0.0, 1.0);
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
