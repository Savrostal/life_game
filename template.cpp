#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define ROWS 25
#define COLS 25

int getNeighbour(bool** field, int x, int y);
int countNeighbours(bool** field, int x, int y);
void print(bool** field, int rows, int cols);
bool isEmpty(bool** field, int rows, int cols);
void nextGen(bool** field, int rows, int cols);
void fillrnd(bool** field, int rows, int cols);
int getRandom(int min, int max);
bool getRandomCell();

int main()
{
	initscr();
	int rows = ROWS, cols = COLS;
	bool** field = new bool*[rows];
	for(int i = 0; i < rows; i++){
		field[i] = new bool[cols];
	}
//	fillrnd(field, rows, cols);
/*	while(!isEmpty(field, rows, cols)){
		nextGen(field, rows, cols);
		print(field, rows, cols);
		usleep(50000);
	}*/
	for(int i = 0; i < 1000; i ++){
		fillrnd(field, rows, cols);
		print(field, rows, cols);
		usleep(50000);
	}
	endwin();
	for(int i = 0; i < rows; i++){
		delete[] field[i]; 
	}
	delete[] field;
	return 0;
}
int getRandom(int min, int max){
	srand(time(NULL));
	int rnd = min + rand() % (max - min + 1);
	return rnd;
}

bool getRandomCell(){
	return getRandom(0,7) < 2;
}

void print(bool** field, int rows, int cols){
	move(0,0);
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			addch(field[i][j] ? '*' : ' ');
		}
		addch('\n');
	}
	refresh();
}
void fillrnd(bool** field, int rows, int cols){
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			field[i][j] = getRandomCell();
		}
	}
}
bool isEmpty(bool** field, int rows, int cols){
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			if(field[i][j]) return false;
		}
	}
	return true;
}
void nextGen(bool** field, int rows, int cols){
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			int cnt = countNeighbours(field, i, j);
			if(field[i][j]) 
				field[i][j] = (cnt == 2 || cnt == 3);
			else
				field[i][j] = cnt == 3;
		}
	}
}
int countNeighbours(bool** field, int x, int y){
	int cnt = 0;
	cnt += getNeighbour(field, x - 1, y - 1);
	cnt += getNeighbour(field, x - 1, y);
	cnt += getNeighbour(field, x - 1, y + 1);
	cnt += getNeighbour(field, x, y - 1);
	cnt += getNeighbour(field, x, y + 1);
	cnt += getNeighbour(field, x + 1, y - 1);
	cnt += getNeighbour(field, x + 1, y);
	cnt += getNeighbour(field, x + 1, y + 1);
	return cnt;
}
int getNeighbour(bool** field, int x, int y){
	if(x < 0 || y < 0 || x >= ROWS || y >= COLS){
		return 0;
	}
	return field[x][y] ? 1 : 0;
}
