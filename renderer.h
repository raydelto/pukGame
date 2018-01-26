#include "constants.h"
#include "vector.h"
#include "puk.h"
#include "world.h"
#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#ifdef __APPLE__
	#include <SDL2/SDL.h>
	#include <SDL2/SDL_opengl.h>
	#include <OpenGL/gl.h>
	#include <OpenGl/glu.h>
	#include <GLUT/glut.h>
	#include <GLKit/GLKMatrix4.h>
#else
	#include <GL/gl.h>
	#include <GL/glu.h>
	#include <SDL/SDL.h>
	#include <SDL/SDL_opengl.h>
#endif


pukk puk;
wrl world;
CPlayer LPlayer;

vec fVect;
vec normal;
SDL_Event event;
int go;

#ifdef __APPLE__
	SDL_Window *window;
#endif

void Init(void)
{
	GLubyte *vend;
	GLubyte *rend;
	GLubyte *ver;
	GLubyte *ext;

	float ambientlight[] = {0.5, 0.5, 0.5, 0.0};
	float diffuselight[] = {0.5, 0.5, 0.5, 0.0};
	float specular[] = {0.8, 0.8, 0.8, 0.0};
	float LightPos[] = {0.0, 0.0, 0.0};

	vend = (GLubyte *)glGetString(GL_VENDOR);
	rend = (GLubyte *)glGetString(GL_RENDERER);
	ver = (GLubyte *)glGetString(GL_VERSION);
	ext = (GLubyte *)glGetString(GL_EXTENSIONS);
	printf("GL_VENDOR: %s\n", vend);
	printf("GL_RENDERER: %s\n", rend);
	printf("GL_VERSION: %s\n", ver);
	printf("GL_EXTENSIONS: %s\n", ext);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	#ifdef __APPLE__
		glMultMatrixf(GLKMatrix4MakePerspective(VIEW_ANGLE * DEGREE_TO_RADIANS, 1.0, 2.0, 20000).m);
	#else
		gluPerspective(VIEW_ANGLE, 1.0, 2.0, 20000);
	#endif

	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientlight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuselight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT0, GL_POSITION, LightPos);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_DEPTH_TEST);

	puk.vel.x = 0.2;
	puk.vel.z = 0.3;
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.0, 0.0, -140.0);
	glRotatef(-60, 1.0, 0.0, 0.0);

	world.Render();

	if (puk.pos.x <= -30)
	{
		normal.x = 1.0;
		normal.z = 0.0;
		fVect = puk.CalcResponse(&normal);
		puk.vel.x = fVect.x;
		puk.vel.z = fVect.z;
		puk.pos.x = -29.9;
	}

	if (puk.pos.x >= 30)
	{
		normal.x = -1.0;
		normal.z = 0.0;
		fVect = puk.CalcResponse(&normal);
		puk.vel.x = fVect.x;
		puk.vel.z = fVect.z;
		puk.pos.x = 29.9;
	}

	if (puk.pos.z <= -60)
	{
		normal.x = 0.0;
		normal.z = 1.0;
		fVect = puk.CalcResponse(&normal);
		puk.vel.x = fVect.x;
		puk.vel.z = fVect.z;
		puk.pos.z = -59.9;
	}

	if (puk.pos.z >= 60)
	{
		normal.x = 0.0;
		normal.z = -1.0;
		fVect = puk.CalcResponse(&normal);
		puk.vel.x = fVect.x;
		puk.vel.z = fVect.z;
		puk.pos.z = 59.9;
	}

	puk.pos.x += puk.vel.x;
	puk.pos.z += puk.vel.z;

	puk.Render();
	LPlayer.Render();
	#ifdef __APPLE__
		SDL_GL_SwapWindow(window);
	#else
		SDL_GL_SwapBuffers();
	#endif

}

int mainLoop(){
	bool done;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
		exit(1);
	}
#ifdef __APPLE__
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow(
		"The Puk Game! v0.1b",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		320,
		200,
		SDL_WINDOW_OPENGL);
	if ( !window )
	{
		fprintf(stderr, "Unable to create OpenGL screen: %s\n", SDL_GetError());
		SDL_Quit();
		exit(2);
	}

	SDL_GL_CreateContext(window);
#else
		if (SDL_SetVideoMode(320, 200, 0, SDL_OPENGL) == NULL)
		{
			fprintf(stderr, "Unable to create OpenGL screen: %s\n", SDL_GetError());
			SDL_Quit();
			exit(2);
		}
		SDL_WM_SetCaption("The Puk Game! v0.1b", NULL);
#endif

	Init();
	done = false;
	while (!done)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				done = true;
			}
		}

		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_ESCAPE || event.key.keysym.sym == SDLK_q)
			{
				done = true;
			}

			if (event.key.keysym.sym == SDLK_UP)
			{
				LPlayer.pos.z += 0.2;
			}

			if (event.key.keysym.sym == SDLK_DOWN)
			{
				LPlayer.pos.z -= 0.2;
			}

			if (event.key.keysym.sym == SDLK_LEFT)
			{
				LPlayer.pos.x -= 0.2;
			}

			if (event.key.keysym.sym == SDLK_RIGHT)
			{
				LPlayer.pos.x += 0.2;
			}
		}

		display();
	}
	return 0;
}
