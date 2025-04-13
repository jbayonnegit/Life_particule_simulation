#include "life.h"

void	set_force(int x, int y, float M_force[6][6])
{
	// LIGNE 1
	if ((x >= WIDTH / 4 + WIDTH / 14 && x <= WIDTH / 4 + WIDTH / 14 * 2) && (y >= HEIGHT / 19 + HEIGHT / 9 && y <= HEIGHT / 19 + HEIGHT / 9 * 2)) // CASE 1
	{
		M_force[0][0] += 0.10;
		if (M_force[0][0] >= 1)
			M_force[0][0] = -1;
	}
	else if ((x >= WIDTH / 4 + WIDTH / 14 * 2 && x <= WIDTH / 4 + WIDTH / 14 * 3) && (y >= HEIGHT / 19 + HEIGHT / 9 && y <= HEIGHT / 19 + HEIGHT / 9 * 2)) // CASE 2
	{
		M_force[0][1] += 0.10;
		if (M_force[0][1] >= 1)
			M_force[0][1] = -1;
	}
	else if ((x >= WIDTH / 4 + WIDTH / 14 * 3 && x <= WIDTH / 4 + WIDTH / 14 * 4) && (y >= HEIGHT / 19 + HEIGHT / 9 && y <= HEIGHT / 19 + HEIGHT / 9 * 2)) // CASE 2
	{
		M_force[0][2] += 0.10;
		if (M_force[0][2] >= 1)
			M_force[0][2] = -1;
	}
	else if ((x >= WIDTH / 4 + WIDTH / 14 * 4 && x <= WIDTH / 4 + WIDTH / 14 * 5) && (y >= HEIGHT / 19 + HEIGHT / 9 && y <= HEIGHT / 19 + HEIGHT / 9 * 2)) // CASE 2
	{
		M_force[0][3] += 0.10;
		if (M_force[0][3] >= 1)
			M_force[0][3] = -1;
	}
	else if ((x >= WIDTH / 4 + WIDTH / 14 * 5 && x <= WIDTH / 4 + WIDTH / 14 * 6) && (y >= HEIGHT / 19 + HEIGHT / 9 && y <= HEIGHT / 19 + HEIGHT / 9 * 2)) // CASE 2
	{
		M_force[0][4] += 0.10;
		if (M_force[0][4] >= 1)
			M_force[0][4] = -1;
	}
	else if ((x >= WIDTH / 4 + WIDTH / 14 * 6 && x <= WIDTH / 4 + WIDTH / 14 * 7) && (y >= HEIGHT / 19 + HEIGHT / 9 && y <= HEIGHT / 19 + HEIGHT / 9 * 2)) // CASE 2
	{
		M_force[0][5] += 0.10;
		if (M_force[0][5] >= 1)
			M_force[0][5] = -1;
	}
	// LIGNE 2
	else if ((x >= WIDTH / 4 + WIDTH / 14 && x <= WIDTH / 4 + WIDTH / 14 * 2) && (y >= HEIGHT / 19 + HEIGHT / 9 * 2 && y <= HEIGHT / 19 + HEIGHT / 9 * 3)) // CASE 1
	{
		M_force[1][0] += 0.10;
		if (M_force[1][0] >= 1)
			M_force[1][0] = -1;
	}
	else if ((x >= WIDTH / 4 + WIDTH / 14 * 2 && x <= WIDTH / 4 + WIDTH / 14 * 3) && (y >= HEIGHT / 19 + HEIGHT / 9 * 2 && y <= HEIGHT / 19 + HEIGHT / 9 * 3)) // CASE 2
	{
		M_force[1][1] += 0.10;
		if (M_force[1][1] >= 1)
			M_force[1][1] = -1;
	}
	else if ((x >= WIDTH / 4 + WIDTH / 14 * 3 && x <= WIDTH / 4 + WIDTH / 14 * 4) && (y >= HEIGHT / 19 + HEIGHT / 9 * 2 && y <= HEIGHT / 19 + HEIGHT / 9 * 3)) // CASE 2
	{
		M_force[1][2] += 0.10;
		if (M_force[1][2] >= 1)
			M_force[1][2] = -1;
	}
	else if ((x >= WIDTH / 4 + WIDTH / 14 * 4 && x <= WIDTH / 4 + WIDTH / 14 * 5) && (y >= HEIGHT / 19 + HEIGHT / 9 * 2 && y <= HEIGHT / 19 + HEIGHT / 9 * 3)) // CASE 2
	{
		M_force[1][3] += 0.10;
		if (M_force[1][3] >= 1)
			M_force[1][3] = -1;
	}
	else if ((x >= WIDTH / 4 + WIDTH / 14 * 5 && x <= WIDTH / 4 + WIDTH / 14 * 6) && (y >= HEIGHT / 19 + HEIGHT / 9 * 2 && y <= HEIGHT / 19 + HEIGHT / 9 * 3)) // CASE 2
	{
		M_force[1][4] += 0.10;
		if (M_force[1][4] >= 1)
			M_force[1][4] = -1;
	}
	else if ((x >= WIDTH / 4 + WIDTH / 14 * 6 && x <= WIDTH / 4 + WIDTH / 14 * 7) && (y >= HEIGHT / 19 + HEIGHT / 9 * 2 && y <= HEIGHT / 19 + HEIGHT / 9 * 3)) // CASE 2
	{
		M_force[1][5] += 0.10;
		if (M_force[1][5] >= 1)
			M_force[1][5] = -1;
	}
    // LIGNE 3
	else if ((x >= WIDTH / 4 + WIDTH / 14 && x <= WIDTH / 4 + WIDTH / 14 * 2) && (y >= HEIGHT / 19 + HEIGHT / 9 * 3 && y <= HEIGHT / 19 + HEIGHT / 9 * 4)) // CASE 1
	{
		M_force[2][0] += 0.10;
		if (M_force[2][0] >= 1)
			M_force[2][0] = -1;
	}
	else if ((x >= WIDTH / 4 + WIDTH / 14 * 2 && x <= WIDTH / 4 + WIDTH / 14 * 3) && (y >= HEIGHT / 19 + HEIGHT / 9 * 3 && y <= HEIGHT / 19 + HEIGHT / 9 * 4)) // CASE 2
	{
		M_force[2][1] += 0.10;
		if (M_force[2][1] >= 1)
			M_force[2][1] = -1;
	}
	else if ((x >= WIDTH / 4 + WIDTH / 14 * 3 && x <= WIDTH / 4 + WIDTH / 14 * 4) && (y >= HEIGHT / 19 + HEIGHT / 9 * 3 && y <= HEIGHT / 19 + HEIGHT / 9 * 4)) // CASE 2
	{
		M_force[2][2] += 0.10;
		if (M_force[2][2] >= 1)
			M_force[2][2] = -1;
	}
	else if ((x >= WIDTH / 4 + WIDTH / 14 * 4 && x <= WIDTH / 4 + WIDTH / 14 * 5) && (y >= HEIGHT / 19 + HEIGHT / 9 * 3 && y <= HEIGHT / 19 + HEIGHT / 9 * 4)) // CASE 2
	{
		M_force[2][3] += 0.10;
		if (M_force[2][3] >= 1)
			M_force[2][3] = -1;
	}
	else if ((x >= WIDTH / 4 + WIDTH / 14 * 5 && x <= WIDTH / 4 + WIDTH / 14 * 6) && (y >= HEIGHT / 19 + HEIGHT / 9 * 3 && y <= HEIGHT / 19 + HEIGHT / 9 * 4)) // CASE 2
	{
		M_force[2][4] += 0.10;
		if (M_force[2][4] >= 1)
			M_force[2][4] = -1;
	}
	else if ((x >= WIDTH / 4 + WIDTH / 14 * 6 && x <= WIDTH / 4 + WIDTH / 14 * 7) && (y >= HEIGHT / 19 + HEIGHT / 9 * 3 && y <= HEIGHT / 19 + HEIGHT / 9 * 4)) // CASE 2
	{
		M_force[2][5] += 0.10;
		if (M_force[2][5] >= 1)
			M_force[2][5] = -1;
	}
        // LIGNE 4
	else if ((x >= WIDTH / 4 + WIDTH / 14 && x <= WIDTH / 4 + WIDTH / 14 * 2) && (y >= HEIGHT / 19 + HEIGHT / 9 * 4 && y <= HEIGHT / 19 + HEIGHT / 9 * 5)) // CASE 1
	{
		M_force[3][0] += 0.10;
		if (M_force[3][0] >= 1)
			M_force[3][0] = -1;
	}
	else if ((x >= WIDTH / 4 + WIDTH / 14 * 2 && x <= WIDTH / 4 + WIDTH / 14 * 3) && (y >= HEIGHT / 19 + HEIGHT / 9 * 4 && y <= HEIGHT / 19 + HEIGHT / 9 * 5)) // CASE 2
	{
		M_force[3][1] += 0.10;
		if (M_force[3][1] >= 1)
			M_force[3][1] = -1;
	}
	else if ((x >= WIDTH / 4 + WIDTH / 14 * 3 && x <= WIDTH / 4 + WIDTH / 14 * 4) && (y >= HEIGHT / 19 + HEIGHT / 9 * 4 && y <= HEIGHT / 19 + HEIGHT / 9 * 5)) // CASE 2
	{
		M_force[3][2] += 0.10;
		if (M_force[3][2] >= 1)
			M_force[3][2] = -1;
	}
	else if ((x >= WIDTH / 4 + WIDTH / 14 * 4 && x <= WIDTH / 4 + WIDTH / 14 * 5) && (y >= HEIGHT / 19 + HEIGHT / 9 * 4 && y <= HEIGHT / 19 + HEIGHT / 9 * 5)) // CASE 2
	{
		M_force[3][3] += 0.10;
		if (M_force[3][3] >= 1)
			M_force[3][3] = -1;
	}
	else if ((x >= WIDTH / 4 + WIDTH / 14 * 5 && x <= WIDTH / 4 + WIDTH / 14 * 6) && (y >= HEIGHT / 19 + HEIGHT / 9 * 4 && y <= HEIGHT / 19 + HEIGHT / 9 * 5)) // CASE 2
	{
		M_force[3][4] += 0.10;
		if (M_force[3][4] >= 1)
			M_force[3][4] = -1;
	}
	else if ((x >= WIDTH / 4 + WIDTH / 14 * 6 && x <= WIDTH / 4 + WIDTH / 14 * 7) && (y >= HEIGHT / 19 + HEIGHT / 9 * 4 && y <= HEIGHT / 19 + HEIGHT / 9 * 5)) // CASE 2
	{
		M_force[3][5] += 0.10;
		if (M_force[3][5] >= 1)
			M_force[3][5] = -1;
	}
            // LIGNE 5
	else if ((x >= WIDTH / 4 + WIDTH / 14 && x <= WIDTH / 4 + WIDTH / 14 * 2) && (y >= HEIGHT / 19 + HEIGHT / 9 * 5 && y <= HEIGHT / 19 + HEIGHT / 9 * 6)) // CASE 1
	{
		M_force[4][0] += 0.10;
		if (M_force[4][0] >= 1)
			M_force[4][0] = -1;
	}
	else if ((x >= WIDTH / 4 + WIDTH / 14 * 2 && x <= WIDTH / 4 + WIDTH / 14 * 3) && (y >= HEIGHT / 19 + HEIGHT / 9 * 5 && y <= HEIGHT / 19 + HEIGHT / 9 * 6)) // CASE 2
	{
		M_force[4][1] += 0.10;
		if (M_force[4][1] >= 1)
			M_force[4][1] = -1;
	}
	else if ((x >= WIDTH / 4 + WIDTH / 14 * 3 && x <= WIDTH / 4 + WIDTH / 14 * 4) && (y >= HEIGHT / 19 + HEIGHT / 9 * 5 && y <= HEIGHT / 19 + HEIGHT / 9 * 6)) // CASE 2
	{
		M_force[4][2] += 0.10;
		if (M_force[4][2] >= 1)
			M_force[4][2] = -1;
	}
	else if ((x >= WIDTH / 4 + WIDTH / 14 * 4 && x <= WIDTH / 4 + WIDTH / 14 * 5) && (y >= HEIGHT / 19 + HEIGHT / 9 * 5 && y <= HEIGHT / 19 + HEIGHT / 9 * 6)) // CASE 2
	{
		M_force[4][3] += 0.10;
		if (M_force[4][3] >= 1)
			M_force[4][3] = -1;
	}
	else if ((x >= WIDTH / 4 + WIDTH / 14 * 5 && x <= WIDTH / 4 + WIDTH / 14 * 6) && (y >= HEIGHT / 19 + HEIGHT / 9 * 5 && y <= HEIGHT / 19 + HEIGHT / 9 * 6)) // CASE 2
	{
		M_force[4][4] += 0.10;
		if (M_force[4][4] >= 1)
			M_force[4][4] = -1;
	}
	else if ((x >= WIDTH / 4 + WIDTH / 14 * 6 && x <= WIDTH / 4 + WIDTH / 14 * 7) && (y >= HEIGHT / 19 + HEIGHT / 9 * 5 && y <= HEIGHT / 19 + HEIGHT / 9 * 6)) // CASE 2
	{
		M_force[4][5] += 0.10;
		if (M_force[4][5] >= 1)
			M_force[4][5] = -1;
	}
             // LIGNE 6
	else if ((x >= WIDTH / 4 + WIDTH / 14 && x <= WIDTH / 4 + WIDTH / 14 * 2) && (y >= HEIGHT / 19 + HEIGHT / 9 * 6 && y <= HEIGHT / 19 + HEIGHT / 9 * 7)) // CASE 1
	{
		M_force[5][0] += 0.10;
		if (M_force[5][0] >= 1)
			M_force[5][0] = -1;
	}
	else if ((x >= WIDTH / 4 + WIDTH / 14 * 2 && x <= WIDTH / 4 + WIDTH / 14 * 3) && (y >= HEIGHT / 19 + HEIGHT / 9 * 6 && y <= HEIGHT / 19 + HEIGHT / 9 * 7)) // CASE 2
	{
		M_force[5][1] += 0.10;
		if (M_force[5][1] >= 1)
			M_force[5][1] = -1;
	}
	else if ((x >= WIDTH / 4 + WIDTH / 14 * 3 && x <= WIDTH / 4 + WIDTH / 14 * 4) && (y >= HEIGHT / 19 + HEIGHT / 9 * 6 && y <= HEIGHT / 19 + HEIGHT / 9 * 7)) // CASE 2
	{
		M_force[5][2] += 0.10;
		if (M_force[5][2] >= 1)
			M_force[5][2] = -1;
	}
	else if ((x >= WIDTH / 4 + WIDTH / 14 * 4 && x <= WIDTH / 4 + WIDTH / 14 * 5) && (y >= HEIGHT / 19 + HEIGHT / 9 * 6 && y <= HEIGHT / 19 + HEIGHT / 9 * 7)) // CASE 2
	{
		M_force[5][3] += 0.10;
		if (M_force[5][3] >= 1)
			M_force[5][3] = -1;
	}
	else if ((x >= WIDTH / 4 + WIDTH / 14 * 5 && x <= WIDTH / 4 + WIDTH / 14 * 6) && (y >= HEIGHT / 19 + HEIGHT / 9 * 6 && y <= HEIGHT / 19 + HEIGHT / 9 * 7)) // CASE 2
	{
		M_force[5][4] += 0.10;
		if (M_force[5][4] >= 1)
			M_force[5][4] = -1;
	}
	else if ((x >= WIDTH / 4 + WIDTH / 14 * 6 && x <= WIDTH / 4 + WIDTH / 14 * 7) && (y >= HEIGHT / 19 + HEIGHT / 9 * 6 && y <= HEIGHT / 19 + HEIGHT / 9 * 7)) // CASE 2
	{
		M_force[5][5] += 0.10;
		if (M_force[5][5] >= 1)
			M_force[5][5] = -1;
	}   
}