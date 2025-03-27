#include "../include/life.h"

void    applie_force(float M_force[6][6], int row, int collum, t_cel *particules)
{
	float	speed;
	float 	f;
	float	beta;

	f = 0;
	beta = D_MIN * 0.3;
	if (beta < D_MIN)
		f = (D_MIN / beta) - 1;
	particules->vx *= M_force[row][collum];
	particules->vy *= M_force[row][collum];
	speed = sqrtf(particules->vx * particules->vx + particules->vy * particules->vy);
	if (speed > V_MAX)
	{
		particules->vx = (particules->vx / speed) * V_MAX; 
		particules->vy = (particules->vy / speed) * V_MAX; 
	}
	else if (speed < V_MIN)
	{
		particules->vx = (particules->vx / speed) * V_MIN; 
		particules->vy = (particules->vy / speed) * V_MIN; 
	}
	particules->x += particules->vx;
	particules->y += particules->vy;
}

void	get_force(t_cel **particles, t_cel *current, float M_force[6][6], int *in_view, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		applie_force(M_force, particles[in_view[i]]->type, current->type, current);
		i++;
	}
}

t_boolean	update_particles(t_cel **particles, float M_force[6][6])
{
	t_quad	*root;
	int		*in_view;
	int		*tmp;
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
	tmp = NULL;
	while (particles[k])
	{
	
		printf("in_view add : %p, tmp add : %p\n", in_view, tmp);
		if (in_view)
			tmp = in_view;
		c = 0;
		if (!find_neighbor(root, particles[k]->x, particles[k]->y, D_MIN, &in_view, &c, particles, particles[k]))
			return (free_tree(root), free(tmp), false);
		if (tmp)
		{
			printf("tmp add : %p\n", tmp);
			//free(tmp);
			tmp = NULL;
		}
		get_force(particles, particles[k], M_force, in_view, c);
		k++;
	}
	//free(in_view);
	return (true);
}
