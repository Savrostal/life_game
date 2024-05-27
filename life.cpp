#include <ncurses.h>
#include <unistd.h>
#include "constants.h"
#include "init_field.h"
#include "get_live_count.h"
#include "cmp_fields.h"
#include "copy_field.h"
#include "next_generation.h"
#include "print.h"


int main()
{
	initscr();

	bool** field = new bool*[HEIGHT];
	for(int i = 0; i < HEIGHT; i++){
		field[i] = new bool[WIDTH];
	}
	bool** prev_field = new bool*[HEIGHT];
	for(int i = 0; i < HEIGHT; i++){
		prev_field[i] = new bool[WIDTH];
	}

	init_field(field);
	int live_points = -1;
	bool is_optimal = false;

	do{
		print(field);
		copy_field(field, prev_field);
		next_generation(field, prev_field);

		is_optimal = cmp_fields(field, prev_field);

		if(is_optimal){
			printw("Optimal configuration detected\n");
		}
		if(live_points == 0) {
			printw("All points died\n");
		}
		usleep(100000);
	}while(live_points != 0 && !is_optimal);


	endwin();

	for(int i = 0; i < HEIGHT; i++){
		delete[] field[i]; 
	}
	delete[] field;
	for(int i = 0; i < HEIGHT; i++){
		delete[] prev_field[i]; 
	}
	delete[] prev_field;

	return 0;
}
