/*
 * player.cpp
 *
 *  Created on: Feb 10, 2018
 *      Author: raydelto
 */

#include "Player.h"

void Player::Render(void)
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
