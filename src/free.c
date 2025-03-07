#include "include/life.h"

void free_particles_init(t_cel **particles, int i)
{
    int n;

    n = 0;
    while (n < i)
    {
        free(particles[n]);
        n++;
    }
    free(particles);
}

void	free_tree(t_quad *root)
{
	if (root->leave)
		free(root->in_view);
	if (root->NE)
	{
		free_tree(root->NE);
		root->NE = NULL;
	}
	if (root->NW)
	{
		free_tree(root->NW);
		root->NE = NULL;
	}
	if (root->SE)
	{
		free_tree(root->SE);
		root->NE = NULL;
	}
	if (root->SW)
	{
		free_tree(root->SW);
		root->NE = NULL;
	}
	free(root);
}