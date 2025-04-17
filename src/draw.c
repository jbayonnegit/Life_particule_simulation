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
		return ;
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

void drawCircle(SDL_Renderer *renderer, int centerX, int centerY, int radius)
{
	int x = radius;
	int y = 0;
	int err = 0;
	
	while (x >= y)
	{
		// Draw 8 points (one in each octant)
		SDL_RenderDrawPoint(renderer, centerX + x, centerY + y);
		SDL_RenderDrawPoint(renderer, centerX + y, centerY + x);
		SDL_RenderDrawPoint(renderer, centerX - y, centerY + x);
		SDL_RenderDrawPoint(renderer, centerX - x, centerY + y);
		SDL_RenderDrawPoint(renderer, centerX - x, centerY - y);
		SDL_RenderDrawPoint(renderer, centerX - y, centerY - x);
		SDL_RenderDrawPoint(renderer, centerX + y, centerY - x);
		SDL_RenderDrawPoint(renderer, centerX + x, centerY - y);
		
		// Update using the midpoint algorithm
		if (err <= 0)
		{
			y += 1;
			err += 2*y + 1;
		}
		if (err > 0)
		{
			x -= 1;
			err -= 2*x + 1;
		}
	}
}

void drawFilledCircle(SDL_Renderer *renderer, int centerX, int centerY, int radius)
{
	for (int w = 0; w < radius * 2; w++)
	{
		for (int h = 0; h < radius * 2; h++)
		{
			int dx = radius - w;
			int dy = radius - h;
			if ((dx*dx + dy*dy) <= (radius * radius))
			{
				SDL_RenderDrawPoint(renderer, centerX + dx, centerY + dy);
			}
		}
	}
}

void	set_color(SDL_Renderer *renderer, t_cel *particles)
{
	if (particles->type == BLUE)
		SDL_SetRenderDrawColor(renderer, 59, 255, 255, 255);
	if (particles->type == RED)
		SDL_SetRenderDrawColor(renderer, 242, 25, 25, 255);
	if (particles->type == ORANGE)
		SDL_SetRenderDrawColor(renderer, 255, 145, 0, 255);
	if (particles->type == YELLOW)
		SDL_SetRenderDrawColor(renderer, 255, 236, 0, 255);
	if (particles->type == PURPLE)
		SDL_SetRenderDrawColor(renderer, 166, 64, 255, 255);
	if (particles->type == GREEN)
		SDL_SetRenderDrawColor(renderer, 52, 211, 24, 255);
}

void	set_color_transparent(SDL_Renderer *renderer, t_cel *particles)
{
	if (particles->type == BLUE)
		SDL_SetRenderDrawColor(renderer, 59, 255, 220, 50);
	if (particles->type == RED)
		SDL_SetRenderDrawColor(renderer, 200, 25, 25, 50);
	if (particles->type == ORANGE)
		SDL_SetRenderDrawColor(renderer, 200, 145, 0, 50);
	if (particles->type == YELLOW)
		SDL_SetRenderDrawColor(renderer, 200, 236, 0, 50);
	if (particles->type == PURPLE)
		SDL_SetRenderDrawColor(renderer, 166, 64, 200, 50);
	if (particles->type == GREEN)
		SDL_SetRenderDrawColor(renderer, 52, 170, 24, 50);
}

void	draw_particles(SDL_Renderer *renderer, t_cel **particles, int radius, float zoom)
{
	int	i;

	i = 0;
	while (particles[i])
	{
		//set_color_transparent(renderer, particles[i]);
		//drawFilledCircle(renderer, particles[i]->x, particles[i]->y, radius + 2);
		//drawCircle(renderer, particles[i]->x * zoom, particles[i]->y * zoom, radius + 2);
		set_color(renderer, particles[i]);
		drawFilledCircle(renderer, particles[i]->x * zoom, particles[i]->y * zoom, radius);

		i++;
	}
}

void	init_menu(t_win *win, float M_force[6][6])
{
	SDL_Rect	M_menu[7][7];
	t_coord		coord;
	int			i;
	int			j;

	i = 0;
	coord.y = HEIGHT / 19;
	while (i < 7)
	{
		coord.x = WIDTH / 4;
		j = 0;
		while (j < 7)
		{
			M_menu[i][j].x = coord.x; 
			M_menu[i][j].y = coord.y;
			M_menu[i][j].w = WIDTH / 14; 
			M_menu[i][j].h = HEIGHT / 9;
			coord.x += WIDTH / 14; 
			j++;
		}		
		coord.y += HEIGHT / 9;
		i++; 
	}
	draw_menu(M_menu, win, M_force);
}

// ADD RENDER TEXT

void	color_switch(float force_value, SDL_Renderer *render)
{
	if (force_value == 1)
		SDL_SetRenderDrawColor(render, 0, 19, 23, 255);
	else if (force_value == -1)
		SDL_SetRenderDrawColor(render, 160, 0, 0, 255);
	else if (force_value < 1 && force_value >= 0.8)
		SDL_SetRenderDrawColor(render, 16, 179, 21, 255);
	else if (force_value < 0.8 && force_value >= 0.6)
		SDL_SetRenderDrawColor(render, 32, 159, 18, 255);
	else if (force_value < 0.6 && force_value >= 0.4)
		SDL_SetRenderDrawColor(render, 48, 139, 16, 255);
	else if (force_value < 0.4 && force_value >= 0.2)
		SDL_SetRenderDrawColor(render, 62, 121, 14, 255);
	else if (force_value < 0.2 && force_value >= 0)
		SDL_SetRenderDrawColor(render, 80, 99, 11, 255);
	else if (force_value < 0 && force_value >= -0.2)
		SDL_SetRenderDrawColor(render, 95, 81, 9, 255);
	else if (force_value < -0.2 && force_value >= -0.4)
		SDL_SetRenderDrawColor(render, 113, 59, 7, 255);
	else if (force_value < -0.4 && force_value >= -0.6)
		SDL_SetRenderDrawColor(render, 130, 39, 5, 255);
	else if (force_value < -0.6 && force_value >= -0.8)
		SDL_SetRenderDrawColor(render, 147, 20, 3, 255);
	else if (force_value < -0.8 && force_value >= -1)
		SDL_SetRenderDrawColor(render, 160, 0, 0, 255);
}

void	draw_menu(SDL_Rect M_menu[7][7], t_win *win, float M_force[6][6])
{
	int		i;
	int		j;

	i = 0;
	SDL_SetRenderDrawColor(win->render, 0, 0, 0, 0);
	SDL_RenderClear(win->render);
	while (i < 7)
	{
		j = 0;
		while (j < 7)
		{
			if ((i == 0 || j == 0) && !(j == 0 && i == 0))
			{
				if ((j == 0 && i == 1) || (j == 1 && i == 0))
					SDL_SetRenderDrawColor(win->render, 59, 255, 255, 255); // BLUE
				else if ((j == 2 && i == 0) || (j == 0 && i == 2))
					SDL_SetRenderDrawColor(win->render, 242, 25, 25, 255); 	// RED
				else if ((j == 3 && i == 0) || (j == 0 && i == 3))
					SDL_SetRenderDrawColor(win->render, 255, 145, 0, 255);	// ORANGE
				else if ((j == 4 && i == 0) || (j == 0 && i == 4))
					SDL_SetRenderDrawColor(win->render, 255, 236, 0, 255); 	// YELLOW
				else if ((j == 5 && i == 0) || (j == 0 && i == 5))
					SDL_SetRenderDrawColor(win->render, 166, 64, 255, 255); // PUPRPLE
				else if ((j == 6 && i == 0) || (j == 0 && i == 6))
					SDL_SetRenderDrawColor(win->render, 52, 211, 24, 255); 	// GREEN
				SDL_RenderFillRect(win->render, &M_menu[i][j]);
			}
			else if (!(j == 0 && i == 0))
			{
				color_switch(M_force[i - 1][j -1], win->render);
				SDL_RenderFillRect(win->render, &M_menu[i][j]);
				SDL_SetRenderDrawColor(win->render, 0, 0, 0, 0);
				SDL_RenderDrawRect(win->render, &M_menu[i][j]);
			}
			j++;
		}
		i++;
	}
	SDL_RenderPresent(win->render);
}