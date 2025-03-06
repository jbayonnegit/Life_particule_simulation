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
