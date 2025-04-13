#include "../include/life.h"

float	rand_position(float min, float max)
{
	float scale;

	scale = rand() / (float)RAND_MAX;
	return (min + scale * (max - min));
}

int	rand_color(void)
{
	return ((rand() % 4));
}

t_cel *new_particle(void)
{
	t_cel	*new;

	new = malloc(sizeof(t_cel));
	if (!new)
		return (NULL);
	new->vx = 0;
	new->vy = 0;
	new->x = rand_position(0, (float)(WIDTH));
	new->y = rand_position(0, (float)(HEIGHT));
	new->type = rand_color();
	return (new);
}

t_cel **cel_init(void)
{
	t_cel	**particles;
	int		i;

	particles = malloc(sizeof(t_cel *) * (NB_PARTICULE + 1));
	if (!particles)
		return (NULL);
	i = 0;
	while (i < NB_PARTICULE)
	{
		particles[i] = new_particle();
		if (!particles[i])
			return (free_particles_init(particles, i), NULL);
		i++;
	}
	return (particles);
} 