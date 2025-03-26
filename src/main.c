#include "../include/life.h"

void	refresh(t_cel **particles, t_win *glb)
{
	float	r;

	r = 3;
	SDL_SetRenderDrawColor(glb->render, 0, 0, 0, 255);
	SDL_RenderClear(glb->render);
	draw_particles(glb->render, particles, &r);
	SDL_RenderPresent(glb->render);
	SDL_Delay(30);
}


void	run(t_cel **particles, t_win *win)
{
	t_boolean	run;
	SDL_Event	event;

	run = true;
	while (run)
	{
		refresh(particles, win);
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
}


int main(void)
{
	t_win	*win;
	t_cel	**particles;

	win = malloc(sizeof(t_win));
	if (!window_intialisation(win))
		return (-1);
	srand((unsigned int)time(NULL));
	particles = cel_init();
	run(particles, win);
	return (0);
}