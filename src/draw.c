#include "../include/life.h"

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
void	draw_particles(SDL_Renderer *renderer, t_cel **particles, float *radius)
{
	int	i;

	i = 0;
	while (particles[i])
	{
		set_color(renderer, particles[i]);
		drawCircle(renderer, particles[i]->x, particles[i]->y, (int)*radius);
		drawFilledCircle(renderer, particles[i]->x, particles[i]->y, (int)*radius);
		i++;
	}
}