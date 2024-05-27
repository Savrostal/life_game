#include "next_generation.h"
#include "constants.h"
#include "count_live_neighbours.h"

void next_generation(bool** field, bool** prev_field){
	for(int i = 0; i < HEIGHT; i++){
		for(int j = 0; j < WIDTH; j++){
			int cnt = count_live_neighbours(prev_field, i, j);
			if(prev_field[i][j]){
				field[i][j] = (cnt == 2 || cnt == 3);
			}
			else{
				field[i][j] = cnt == 3;
			}
		}
	}
}
