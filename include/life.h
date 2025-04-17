#ifndef LIFE_H
# define LIFE_H

# define V_MAX 3.5f
# define V_MIN 0.01f
# define NB_PARTICULE 10000
# define RAYON 1
# define HEIGHT 900
# define WIDTH 1440
# define M_PI 3.14159265358979323846
# define D_MIN 20.0f
# define QUAD_CAP 300
# include </opt/homebrew/include/SDL2/SDL.h>
# include </opt/homebrew/include/SDL2/SDL_ttf.h>
# include <stdlib.h>
# include <math.h>
# include <time.h>
# include <stdlib.h>
# include <math.h>

typedef struct s_coord
{
	int	x;
	int	y;
}			t_coord;

typedef enum s_boolean
{
	false,
	true,
}			t_boolean;

typedef	enum s_type
{
	BLUE,
	RED,
	ORANGE,
	YELLOW,
	PURPLE,
	GREEN,
}			t_type;

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

// CEL 

t_cel 		**cel_init(void);
t_boolean	update_particles(t_cel **particles, float M_force[6][6], t_win *win);

// WINDOW INIT

t_boolean	window_intialisation(t_win *win);
t_boolean	win_menu_initialisation(t_win *win);
void		window_clear(t_win *glb);

// CREATE TREE

t_quad  	*quadtree(int max_x, int min_x, int max_y, int min_y, t_cel **particles, int *view, int nb_v, int *k);

// FREE 

void		free_tree(t_quad *root);
void 		free_particles_init(t_cel **particles, int i);

// SEARCH IN TREE
int			*in_view_realloc(int *old, int add, int nb);
int			*view_init_first(void);
t_boolean	find_neighbor(t_quad *root, float x, float y, int **neighbor, int *count, t_cel **particles, t_cel *current);
int			**neighbour_tab_init(t_quad *root, t_cel **cel);


// DRAW

void		draw_tree(t_quad *root, t_win *glb);
void		init_menu(t_win *win, float M_force[6][6]);
void		draw_particles(SDL_Renderer *renderer, t_cel **particles, int radius, float zoom);
void		draw_menu(SDL_Rect M_menu[7][7], t_win *win, float M_force[6][6]);

// SIMULATION FORCES

void		set_force(int x, int y, float M_force[6][6]);
void		get_force(t_cel **particles, t_cel *current, float M_force[6][6], int *in_view, int k);

// MATH

float		rand_position(float min, float max);

#endif