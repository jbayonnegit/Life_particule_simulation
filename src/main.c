#include "../include/life.h"

t_boolean	refresh(t_cel **particles, t_win *glb, float M_force[6][6])
{
	float	r;

	r = 2;
	SDL_SetRenderDrawColor(glb->render, 5, 23, 50, 255);
	SDL_RenderClear(glb->render);
	//if (!update_particles(particles, M_force))
	//	return (false);
	draw_particles(glb->render, particles, &r);
	SDL_RenderPresent(glb->render);
	SDL_Delay(30);
	return (true);
}

void	run_menu(float *M_force[6][6], t_win *win)
{
	t_boolean	run;
	SDL_Event	event;

	run = true;
	while (run)
	{
		init_menu(win);
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_KEYUP)
			{
				if (event.key.keysym.sym == SDLK_RETURN)
				{
					run = false;
				}
			}
		}
	}
}

t_boolean	run_simulation(t_cel **particles, t_win *win)
{
	t_boolean	run;
	SDL_Event	event;
	float		M_force[6][6];

	run = true;
	run_menu(&M_force, win);
	while (run)
	{
		if (!refresh(particles, win, M_force))
			return (false);
		while(SDL_PollEvent(&event))
		{
			if (event.type == SDL_WINDOWEVENT)
			{
				if (event.window.event == SDL_WINDOWEVENT_CLOSE)
				{
					window_clear(win);
					run = false;
				}
			}
		}
	}
	return (true);
}


int main(void)
{
	t_win	*win;
	t_cel	**particles;

	win = malloc(sizeof(t_win));
	if (!window_intialisation(win))
		return (1);
	srand((unsigned int)time(NULL));
	particles = cel_init();
	if (!particles)
		return (window_clear(win), 1);
	if (!run_simulation(particles, win))
		return (window_clear(win), 1);
	return (0);
}