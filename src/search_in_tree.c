#include "life.h"

float distance_euclidienne(float x1, float y1, float x2, float y2) {
    float dx = x2 - x1;
    float dy = y2 - y1;
    return (sqrt(dx * dx + dy * dy));
}

t_boolean rect_intersects_circle(SDL_Point min, SDL_Point max, float x, float y, float r) 
{
	float closestX = fmax(min.x, fmin(x, max.x));
	float closestY = fmax(min.y, fmin(y, max.y));

	float distanceX = x - closestX;
	float distanceY = y - closestY;
	float distanceSquared = (distanceX * distanceX) + (distanceY * distanceY);

	if (distanceSquared <= r * r)
		return (true);
	else
		return (false);
}

t_boolean   find_neighbor(t_quad *root, float x, float y, float r, int **neighbor, int *count, t_cel **particles, t_cel *current)
{
	int		i;
	int		d;
	int		*tmp;

	i = 0;
	d = 0;
	if (!rect_intersects_circle(root->min, root->max, x, y, r))
		return (true);
	if (root->leave == true)
	{
		while (i < root->nb_view)
		{
			d = distance_euclidienne(x, y, particles[root->in_view[i]]->x, particles[root->in_view[i]]->y);
			if (d <= r)
			{
				(*count) += 1;
				tmp = (*neighbor);
				(*neighbor) = in_view_realloc(*neighbor, root->in_view[i], *count);
				if (!*neighbor)
                    return (free(tmp), false);
				free(tmp);
			}
			i++;
		}
	}
	else
	{
		if (!find_neighbor(root->NW, x, y, r, neighbor, count, particles, current))
            return (false);
		if (!find_neighbor(root->NE, x, y, r, neighbor, count, particles, current))
            return (false);
		if (!find_neighbor(root->SE, x, y, r, neighbor, count, particles, current))
            return (false);
		if (!find_neighbor(root->SW, x, y, r, neighbor, count, particles, current))
            return (false);
	}
	return (true);
}

int	*view_init_first(void)
{
	int	*view_init;

	int	i;
	view_init = malloc(sizeof(int) * (NB_PARTICULE + 1));
	if (!view_init)
        return (NULL);
	i = 0;
	while (i < NB_PARTICULE)
	{
		view_init[i] = i;
		i++; 
	}
	view_init[i] = 0;
	return (view_init);
}