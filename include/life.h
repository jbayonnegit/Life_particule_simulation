#ifndef LIFE_H
# define LIFE_H

# define V_MAX 8
# define V_MIN 3
# define NB_PARTICULE 1000
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
	t_boolean	attract_by_red;
	t_boolean	attract_by_purple;
}				t_color;

typedef struct s_particles_rules
{
	t_color	BLUE;
	t_color	RED;
	t_color	YELLOW;
	t_color	ORANGE;
	t_color	RED;
	t_color	PURPLE;
}				t_rules;

typedef struct cel
{
	float	x;
	float	y;
	float	vx;
	float	vy;
	t_type	COLOR;

}			t_cel;

typedef struct s_win
{
	SDL_Renderer 	*render;
	SDL_Window		*window; 
}				t_win;

t_boolean	window_intialisation(t_win *win);
t_cel **cel_init(void);

#endif