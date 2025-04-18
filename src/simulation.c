#include "../include/life.h"

void	resolve_collision(t_cel *current, t_cel *neigbor)
{
	float delta_norme;
	float delta_x;
	float delta_y;
	float collapse;
	
	collapse = 0;
	delta_x = current->x - neigbor-> x;
	delta_y = current->y - neigbor-> y;
	delta_norme = sqrtf(delta_x * delta_x + delta_y * delta_y);
	if (delta_norme < (2 * RAYON) + 5 && delta_norme != 0)
	{
		if (delta_norme == 0)
		{
			current->x += RAYON * 2 + 5;
			current->y += RAYON * 2 + 5;
		}
		collapse = (((RAYON * 2) + 5) - delta_norme) / 2.0f;
		
		delta_x = delta_x / delta_norme;
		current->x += delta_x * collapse;
		neigbor->x -= delta_x * collapse;
		
		delta_y = delta_y / delta_norme;
		current->y += delta_y * collapse;
		neigbor->y -= delta_y * collapse;
	}
}

void    applie_force(float M_force[6][6], t_cel *neighbor, t_cel *current)
{
	float	delta_x;
	float	delta_y;
	float	force;

	delta_y = current->y - neighbor->y;
	delta_x = current->x - neighbor->x;
	force = -M_force[current->type][neighbor->type];
	delta_y *= force;
	delta_x *= force;
	current->vx += delta_x;
	current->vy += delta_y;
}

void	to_zero(t_cel *current)
{
	if (current->vx > 0)
	{
		current->vx -= 0.07;
		if (current->vx < 0)
			current->vx = 0;
	}
	else
	{
		current->vx += 0.07;
		if (current->vx > 0)
			current->vx = 0;
	}
	if (current->vy > 0)
	{
		current->vy -= 0.07;
		if (current->vy < 0)
			current->vy = 0;
	}
	else
	{
		current->vy += 0.07;
		if (current->vy > 0)
			current->vy = 0;
	}
}

void	get_force(t_cel **particles, t_cel *current, float M_force[6][6], int *in_view, int k)
{
	int		i;
	float	dif;
	float	speed;

	i = 1;
	dif = 0;
	while (i < in_view[0])
	{
		if (in_view[i] == k)
			i++;
		if (i >= in_view[0])
			break ;
		applie_force(M_force, particles[in_view[i]], current);
		i++;
	}
	speed = sqrtf(current->vx * current->vx + current->vy * current->vy);
	if (speed > V_MAX && speed != 0)
	{
		current->vx = (current->vx / speed) * V_MAX;
		current->vy = (current->vy / speed) * V_MAX;
	}
	if (speed < V_MIN && speed != 0)
	{
	    current->vx = (current->vx / speed) * V_MIN;
	    current->vy = (current->vy / speed) * V_MIN;
	}
	current->x += current->vx;
	current->y += current->vy;
	if (current->x >= WIDTH)
	{
		dif = WIDTH - current->x;
		current->x = dif;
	}
	else if (current->x <= 0)
		current->x += WIDTH;
	if (current->y >= HEIGHT)
	{
		dif = HEIGHT - current->y;
		current->y = dif;
	}
	else if (current->y <= 0)
		current->y += HEIGHT;
	to_zero(current);
}

void	collision(t_cel **particles, t_quad *root, int **in_view)
{
	int	k;
	int	i;

	k = 0;
	while (particles[k])
	{
		i = 1;
		while (i < in_view[k][0])
		{
			resolve_collision(particles[k], particles[in_view[k][i]]);
			i++;
		}
		k++;
	}
}

void	free_tab(int **tab)
{
	int	i;

	i = 0;
	while (i < NB_PARTICULE)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

t_boolean	update_particles(t_cel **particles, float M_force[6][6], t_win *win)
{
	t_quad	*root;
	int		**neighbour_tab;
	int		*in_view;
	int		k;

	k = 0;
	in_view = view_init_first();
	if (!in_view)
		return (false);
	root = quadtree(WIDTH, 0, HEIGHT, 0, particles, in_view, NB_PARTICULE, &k);
	if (!root)
		return (free(in_view), false);
	k = 0;
	free(in_view);
	in_view = NULL;
	neighbour_tab = neighbour_tab_init(root, particles);
	if (!neighbour_tab)
		return (free_tree(root), false);
	while (particles[k])
	{
		get_force(particles, particles[k], M_force, neighbour_tab[k], k);
		k++;
	}
	collision(particles, root, neighbour_tab);
	free_tab(neighbour_tab);
	free_tree(root);
	return (true);
}
