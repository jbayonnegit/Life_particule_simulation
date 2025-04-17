#include "life.h"

float distance_euclidienne(float x1, float y1, float x2, float y2) {
    float dx = x2 - x1;
    float dy = y2 - y1;
    return (sqrt(dx * dx + dy * dy));
}

t_boolean rect_intersects_circle(SDL_Point min, SDL_Point max, float x, float y) 
{
	float closestX = fmax(min.x, fmin(x, max.x));
	float closestY = fmax(min.y, fmin(y, max.y));

	float distanceX = x - closestX;
	float distanceY = y - closestY;
	float distanceSquared = (distanceX * distanceX) + (distanceY * distanceY);

	if (distanceSquared <= D_MIN * D_MIN)
		return (true);
	else
		return (false);
}

t_boolean   find_neighbor(t_quad *root, float x, float y, int **neighbor, int *count, t_cel **particles, t_cel *current)
{
	int		i;
	int		d;
	int		*tmp;

	i = 0;
	d = 0;
	if (!root)
		return (true);
	if (!rect_intersects_circle(root->min, root->max, x, y))
		return (true);
	if (root->leave == true)
	{
		while (i < root->nb_view)
		{
			d = distance_euclidienne(x, y, particles[root->in_view[i]]->x, particles[root->in_view[i]]->y);
			if (d <= D_MIN)
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
		if (!find_neighbor(root->NW, x, y, neighbor, count, particles, current))
            return (false);
		if (!find_neighbor(root->NE, x, y, neighbor, count, particles, current))
            return (false);
		if (!find_neighbor(root->SE, x, y, neighbor, count, particles, current))
            return (false);
		if (!find_neighbor(root->SW, x, y, neighbor, count, particles, current))
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

void	free_tab_init(int **tab, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	*add_nb_to_view(int *old, int k)
{
	int	*new;
	int	i;

	new = malloc(sizeof(int) * (k + 1));
	if (!new)
		return (free(old), NULL);
	i = 0;
	while (i < k + 1)
	{
		if (i == 0)
		{
			new[i] = k + 1;
			i++;
			if (i >= k + 1)
				break ;
		}
		new[i] = old[i - 1];
		i++;
	}
	free(old);
	return (new);
}

int	**neighbour_tab_init(t_quad *root, t_cel **cel)
{
	int	**tab;
	int	*tmp;
	int	k;
	int	n;

	tab = malloc(sizeof(int *) * NB_PARTICULE);
	if (!tab)
		return (NULL);
	k = 0;
	n = 0;
	while (n < NB_PARTICULE)
	{
		tmp = NULL;
		k = 0;
		if (!find_neighbor(root, cel[n]->x, cel[n]->y, &tmp, &k, cel, cel[n]))
			return (free_tab_init(tab, n), NULL);
		tmp = add_nb_to_view(tmp, k);
		if (!tmp)
			return (free_tab_init(tab, n), NULL);
		tab[n] = tmp;
		n++;
	}
	return (tab);
}
