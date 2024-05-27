#include "cmp_fields.h"
#include "constants.h"

bool cmp_fields(bool** f1, bool** f2){
	for(int i = 0; i < HEIGHT; i++){
		for(int j = 0; j < WIDTH; j++){
			if(f1[i][j] != f2[i][j])
				return false;
		}
	}
	return true;
}
