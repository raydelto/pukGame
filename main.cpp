#include "Renderer.h"

int main(int argc, char **argv)
{
	Renderer* renderer = new Renderer();
	return renderer -> MainLoop();
}
