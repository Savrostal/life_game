#include "check_neighbour.h"
#include "constants.h"

int check_neighbour(bool** field, int y, int x){
	if(y < 0 || x < 0)
		return 0;
	if(y >= HEIGHT || x >= WIDTH)
		return 0;
	return field[y][x] ? 1 : 0;
}
