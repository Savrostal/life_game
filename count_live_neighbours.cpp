#include "count_live_neighbours.h"
#include "check_neighbour.h"
#include "constants.h"

int count_live_neighbours(bool** field, int y, int x){
	int count = 0;
	count += check_neighbour(field, y - 1, x - 1);
	count += check_neighbour(field, y - 1, x);
	count += check_neighbour(field, y - 1, x + 1);
	count += check_neighbour(field, y, x - 1);
	count += check_neighbour(field, y, x + 1);
	count += check_neighbour(field, y + 1, x - 1);
	count += check_neighbour(field, y + 1, x);
	count += check_neighbour(field, y + 1, x + 1);
	return count;
}
