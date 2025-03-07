#include "include/life.h"

int main(int argc, char **argv)
{
	t_win	win;
	t_cel	**particles;

	if (!window_intialisation(&win))
		return (-1);
	
	particles = cel_init();
}