#include "../include/life.h"

void	draw_tree(t_quad *root, t_win *glb)
{
	SDL_Rect	quad;

	quad.x = root->min.x;
	quad.y = root->min.y;
	quad.w = root->max.x;
	quad.h = root->max.y;
	SDL_SetRenderDrawColor(glb->render, 50, 255, 0, 255);
	SDL_RenderDrawRect(glb->render, &quad);
	if (root->leave == true)
	{
		return ;
	}
	else
	{
		if (root->NW)
			draw_tree(root->NW, glb);
		if (root->NE)
			draw_tree(root->NE, glb);
		if (root->SW)
			draw_tree(root->SW, glb);
		if (root->SE)
			draw_tree(root->SE, glb);
	}
}

t_boolean	refresh(t_cel **particles, t_win *glb, float M_force[6][6])
{
	float	r;

	r = 5;
	SDL_SetRenderDrawColor(glb->render, 2, 11, 20, 255);
	SDL_RenderClear(glb->render);
	if (!update_particles(particles, M_force, glb))
		return (false);
	draw_particles(glb->render, particles, &r);
	SDL_RenderPresent(glb->render);
	SDL_Delay(30);
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

t_boolean	run_menu(float M_force[6][6], t_win *win)
{
	t_boolean	run;
	SDL_Event	event;

	run = true;
	random_init_force(M_force);
	while (run)
	{
		init_menu(win, M_force);
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_KEYUP)
			{
				if (event.key.keysym.sym == SDLK_RETURN)
				{
					run = false;
				}
			}
			if (event.type == SDL_WINDOWEVENT)
			{
				if (event.window.event == SDL_WINDOWEVENT_CLOSE)
				{
					window_clear(win);
					run = false;
					return (false);
				}
			}
		}
	}
	return (true);
}

t_boolean	run_simulation(t_cel **particles, t_win *win)
{
	t_boolean	run;
	SDL_Event	event;
	float		M_force[6][6];

	run = true;
	if (!run_menu(M_force, win))
		return (true);
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