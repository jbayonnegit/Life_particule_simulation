#include "../include/life.h"

t_boolean	window_intialisation(t_win *win)
{
	if (SDL_Init(SDL_INIT_EVENTS | SDL_INIT_AUDIO | SDL_INIT_VIDEO) < 0)
		return (false);
	win->window = SDL_CreateWindow("Life Particule Simulation", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
	if (!win->window)
	{
		free(win);
		win = NULL;
		return (false);
	}
	win->render = SDL_CreateRenderer(win->window, -1, SDL_RENDERER_ACCELERATED);
	if (!win->render)
	{
		free(win->window);
		win->window = NULL;
		free(win);
		win = NULL;
		return (false);
	}
	return (true);
}
