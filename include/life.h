#ifndef LIFE_H
# define LIFE_H

# define V_MAX 8
# define V_MIN 3
# define NB_PARTICULE 10000
# define HEIGHT 1080
# define WIDTH 1920
# define M_PI 3.14159265358979323846
# define D_MIN 100
# define QUAD_CAP 40
# include <SDL2/SDL.h>
# include <stdlib.h>
# include <math.h>
# include <time.h>
# include <stdlib.h>
# include <math.h>

typedef enum s_boolean
{
	false,
	true,
}			t_boolean;

typedef	enum s_type
{
	RED,
	BLUE,
	GREEN,
	YELLOW,
	ORANGE,
	PURPLE,
}			t_type;

typedef	struct s_color
{
	t_type		color;
	t_boolean	attract_by_blue;
	t_boolean	attract_by_red;
	t_boolean	attract_by_yellow;
	t_boolean	attract_by_orange;
	t_boolean	attract_by_color;
	t_boolean	attract_by_purple;
}				t_color;

typedef struct s_particles_rules
{
	t_color	BLUE;
	t_color	RED;
	t_color	YELLOW;
	t_color	ORANGE;
	t_color	GREEN;
	t_color	PURPLE;
}				t_rules;

typedef struct cel
{
	float		x;
	float		y;
	float		vx;
	float		vy;
	t_type		type;
	SDL_Color	color;

}			t_cel;

typedef struct s_win
{
	SDL_Renderer 	*render;
	SDL_Window		*window; 
}				t_win;

typedef struct s_quadtree
{
	SDL_Point			min;			// Point superieur gauche
	SDL_Point			max;			// Point inferieur droit
	t_boolean			leave;			// True si c'est une feuille, False si c'est une branche
	int					*in_view;		// Array des Boids en vue
	int					nb_view;		// Array des Boids en vue
	struct s_quadtree	*NW;			// Branche Nord Ouest
	struct s_quadtree	*NE;			// Branche Nord Est
	struct s_quadtree	*SW;			// Branche Sud Ouest
	struct s_quadtree	*SE;			// Branche Sud Est
}				t_quad;


t_boolean	window_intialisation(t_win *win);
t_cel 		**cel_init(void);
t_quad  	*quadtree(int max_x, int min_x, int max_y, int min_y, t_cel **particles, int *view, int nb_v, int *k);
void		free_tree(t_quad *root);
void 		free_particles_init(t_cel **particles, int i);
void		window_clear(t_win *glb);
void		draw_particles(SDL_Renderer *renderer, t_cel **particles, float *radius);

#endif