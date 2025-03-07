#include "include/life.h"


t_quad  *quadtree(int max_x, int min_x, int max_y, int min_y, t_cel **particles, int *view, int nb_v, int *k)
{
	t_quad	*root;
	int		*tmp;
	int		c;
	int		i;

	i = 0;
	c = 0;
	 if (*k >= NB_PARTICULE)
	 	return (NULL);
	root = quadrant_init(max_x, max_y, min_x, min_y);
	if (!root)
		return (NULL);
	while (i < nb_v)
	{	
		if ((particles[view[i]]->x <= max_x && particles[view[i]]->x >= min_x) && (particles[view[i]]->y <= max_y && particles[view[i]]->y >= min_y))
		{
			c++;
			tmp = root->in_view;
			root->in_view = in_view_realloc(root->in_view, view[i], c);
			if (tmp)
				free(tmp);
		}
		i++;
	}
	if (c > QUAD_CAP)
	{
		int mid_x = (max_x + min_x) / 2;
		int mid_y = (max_y + min_y) / 2;

		root->NW = quadtree(mid_x, min_x, mid_y, min_y, particles, root->in_view, c, k);
		if (!root->NW)
			return (free(root->in_view), NULL);
		root->NE = quadtree(max_x, mid_x, mid_y, min_y, particles, root->in_view, c, k);
		if (!root->NE)
			return (free(root->in_view), free_tree(root->NW), NULL);
		root->SW = quadtree(mid_x, min_x, max_y, mid_y, particles, root->in_view, c, k);
		if (!root->SW)
			return (free(root->in_view), free_tree(root->NW), free_tree(root->NE), NULL);		
		root->SE = quadtree(max_x, mid_x, max_y, mid_y, particles, root->in_view, c, k);
		if (!root->SW)
			return (free(root->in_view), free_tree(root->NW), free_tree(root->NE), free_tree(root->SW), NULL);	
		free(root->in_view);
	}
	else
	{
		*k += c;
		root->leave = true;
		root->nb_view = c;
	}
	return (root);
}