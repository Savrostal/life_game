#include "get_live_count.h"
#include "constants.h"

unsigned int get_live_count(bool** field){
	unsigned int count = 0;
	for(int i = 0; i < HEIGHT; i++){
		for(int j = 0; j < WIDTH; j++){
			if(field[i][j])
				count++;
		}
	}
	return count;
}
