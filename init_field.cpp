#include "init_field.h"
#include "constants.h"

void init_field(bool** field){
	std::random_device rnd;
	std::mt19937 gen(rnd());
	std::uniform_int_distribution<> dis(1, 10000);

	for(int i = 0; i < HEIGHT; i++){
		for(int j = 0; j < WIDTH; j++){
			unsigned int num = dis(gen);
			field[i][j] = num % 2 == 0;
		}
	}
}
