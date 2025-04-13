#include "../include/life.h"

t_boolean	refresh(t_cel **particles, t_win *glb, float M_force[6][6], float zoom)
{
	SDL_SetRenderDrawColor(glb->render, 2, 11, 20, 255);
	SDL_RenderClear(glb->render);
	if (!update_particles(particles, M_force, glb))
		return (false);
	draw_particles(glb->render, particles, RAYON, zoom);
	SDL_RenderPresent(glb->render);
	SDL_Delay(5);
	return (true);
}

void	random_init_force(float M_menu[6][6])
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
			M_menu[i][j] = rand_position(-1.0, 1.0);
	}
}

t_boolean	run_menu(float M_force[6][6], t_win *win, int k)
{
	t_boolean	run;
	SDL_Event	event;

	run = true;
	if (k == 0)
		random_init_force(M_force);
	while (run)
	{
		init_menu(win, M_force);
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_KEYUP)
			{
				if (event.key.keysym.sym == SDLK_RETURN)
					run = false;
			}
			if (event.type == SDL_WINDOWEVENT)
			{
				if (event.window.event == SDL_WINDOWEVENT_CLOSE)
				{
					//window_clear(win);
					run = false;
					return (false);
				}
			}
			if (event.type == SDL_MOUSEBUTTONDOWN)
				set_force(event.button.x, event.button.y, M_force);
		}
	}
	return (true);
}

t_boolean	run_simulation(t_cel **particles, t_win *win)
{
	t_boolean	run;
	SDL_Event	event;
	float		M_force[6][6];
	float			zoom;

	zoom = 1;
	run = true;
	if (!run_menu(M_force, win, 0))
		return (true);
	while (run)
	{
		if (!refresh(particles, win, M_force, zoom))
			return (false);
	//	printf ("green green : %f\n", M_force[5][5]);
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
			if (event.type == SDL_KEYUP)
			{
				if (event.key.keysym.sym == SDLK_RETURN)
				{
					if (!run_menu(M_force, win, 1))
						return (true);	
				}
			}
			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_UP)
					zoom += 0.5;
				if (event.key.keysym.sym == SDLK_DOWN)
					zoom -= 0.5;
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