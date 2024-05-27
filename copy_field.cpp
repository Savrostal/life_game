#include "copy_field.h"
#include "constants.h"

void copy_field(bool** src, bool** dest){
	for(int i = 0; i < HEIGHT; i++){
		for(int j = 0; j < WIDTH; j++){
			dest[i][j] = src[i][j];
		}
	}
}
