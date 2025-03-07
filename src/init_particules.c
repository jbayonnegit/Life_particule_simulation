#include "include/life.h"

float	rand_position(float min, float max)
{
	float scale;

	srand((unsigned int)time(NULL));
	scale = rand() / (float)RAND_MAX;
	return (min + scale * (max - min));
}

int	rand_color(void)
{
	return ((rand() % 5) + 1);
}

t_cel *new_particules(void)
{
	t_cel	*new;

	new = malloc(sizeof(t_cel));
	if (!new)
		return (NULL);
	new->vx = 0;
	new->vy = 0;
	new->x = rand_position(10.0f, (float)(WIDTH - 10));
	new->y = rand_position(10.0f, (float)(HEIGHT - 10));
	new->COLOR = rand_color();
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
} 