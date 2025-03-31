#include "../include/life.h"

void    applie_force(float M_force[6][6], t_cel *neighbor, t_cel *current)
{
	float	delta_x;
	float	delta_y;

	delta_y = current->y - neighbor->y;
	delta_x = current->x - neighbor->x;
	delta_y *= M_force[neighbor->type][current->type];
	delta_x *= M_force[neighbor->type][current->type];
	current->vx += delta_x;
	current->vy += delta_y;
}

void	get_force(t_cel **particles, t_cel *current, float M_force[6][6], int *in_view, int nb)
{
	int		i;
	float	speed;

	i = 0;
	while (i < nb)
	{
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
}

t_boolean	update_particles(t_cel **particles, float M_force[6][6], t_win *win)
{
	t_quad	*root;
	int		*in_view;
	int		c;
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
	while (particles[k])
	{
		c = 0;
		if (!find_neighbor(root, particles[k]->x, particles[k]->y, D_MIN, &in_view, &c, particles, particles[k]))
			return (free_tree(root), false);
		get_force(particles, particles[k], M_force, in_view, c);
		free(in_view);
		in_view = NULL;
		k++;
	}
	(void)win;
	//draw_tree(root, win);
	//free(in_view);
	free_tree(root);
	return (true);
}
