/*
 * Renderer.cpp
 *
 *  Created on: Feb 11, 2018
 *      Author: raydelto
 */

#include "Renderer.h"

void Renderer::Init()
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

	_puk -> vel.x = 0.2;
	_puk -> vel.z = 0.3;
}

void Renderer::Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.0, 0.0, -140.0);
	glRotatef(-60, 1.0, 0.0, 0.0);

	_world -> Render();

	if (_puk -> pos.x <= -30)
	{
		_normal -> x = 1.0;
		_normal-> z = 0.0;
		_fVect = _puk -> CalcResponse(_normal);
		_puk -> vel.x = _fVect -> x;
		_puk -> vel.z = _fVect -> z;
		_puk -> pos.x = -29.9;
	}

	if (_puk -> pos.x >= 30)
	{
		_normal -> x = -1.0;
		_normal -> z = 0.0;
		_fVect = _puk -> CalcResponse(_normal);
		_puk -> vel.x = _fVect -> x;
		_puk -> vel.z = _fVect -> z;
		_puk -> pos.x = 29.9;
	}

	if (_puk -> pos.z <= -60)
	{
		_normal -> x = 0.0;
		_normal -> z = 1.0;
		_fVect = _puk -> CalcResponse(_normal);
		_puk -> vel.x = _fVect -> x;
		_puk -> vel.z = _fVect -> z;
		_puk -> pos.z = -59.9;
	}

	if (_puk -> pos.z >= 60)
	{
		_normal -> x = 0.0;
		_normal -> z = -1.0;
		_fVect = _puk -> CalcResponse(_normal);
		_puk -> vel.x = _fVect -> x;
		_puk -> vel.z = _fVect -> z;
		_puk -> pos.z = 59.9;
	}

	_puk -> pos.x += _puk -> vel.x;
	_puk -> pos.z += _puk -> vel.z;

	_puk -> Render();
	_LPlayer -> Render();
	#ifdef __APPLE__
		SDL_GL_SwapWindow(_window);
	#else
		SDL_GL_SwapBuffers();
	#endif
}

Renderer::Renderer()
{
	_puk = new pukk();
	_world = new wrl();
	_LPlayer = new CPlayer();
	_fVect = new vec();
	_normal = new vec();
#ifdef __APPLE__
	_window = NULL;
#endif

}

Renderer::~Renderer()
{
	delete _puk;
	delete _world;
	delete _LPlayer;
	delete _fVect;
	delete _normal;
}

int Renderer::MainLoop()
{
	bool done = false;
	SDL_Event event;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
		exit(1);
	}
#ifdef __APPLE__
	SDL_Init(SDL_INIT_VIDEO);
	_window = SDL_CreateWindow(
		"The Puk Game! v0.1b",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		320,
		200,
		SDL_WINDOW_OPENGL);
	if ( !_window )
	{
		fprintf(stderr, "Unable to create OpenGL screen: %s\n", SDL_GetError());
		SDL_Quit();
		exit(2);
	}

	SDL_GL_CreateContext(_window);
#else
		if (SDL_SetVideoMode(320, 200, 0, SDL_OPENGL) == NULL)
		{
			fprintf(stderr, "Unable to create OpenGL screen: %s\n", SDL_GetError());
			SDL_Quit();
			exit(2);
		}
		SDL_WM_SetCaption("The Puk Game! v0.1b", NULL);
#endif

	this -> Init();

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
				_LPlayer -> pos.z += 0.2;
			}

			if (event.key.keysym.sym == SDLK_DOWN)
			{
				_LPlayer -> pos.z -= 0.2;
			}

			if (event.key.keysym.sym == SDLK_LEFT)
			{
				_LPlayer -> pos.x -= 0.2;
			}

			if (event.key.keysym.sym == SDLK_RIGHT)
			{
				_LPlayer -> pos.x += 0.2;
			}
		}

		this -> Display();
	}
	return 0;
}
