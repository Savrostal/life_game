#include "print.h"
#include <ncurses.h>
#include "constants.h"

void print(bool** field){
	move(0,0);
	for(int i = 0; i < HEIGHT; i++){
		for(int j = 0; j < WIDTH; j++){
			addch(field[i][j] ? '*' : ' ');
		}
		addch('\n');
	}
	refresh();
}
