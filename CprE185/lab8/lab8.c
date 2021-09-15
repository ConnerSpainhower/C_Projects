// WII-MAZE Skeleton code written by Jason Erbskorn 2007
// Edited for ncurses 2008 Tom Daniels
// Updated for Esplora 2013 TeamRursch185
// Updated for DualShock 4 2016 Rursch


// Headers
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ncurses/ncurses.h>
#include <unistd.h>
#include <time.h>

// Mathematical constants
#define PI 3.14159

// Screen geometry
// Use ROWS and COLS for the screen height and width (set by system)
// MAXIMUMS
#define NUMCOLS 100
#define NUMROWS 72

// Character definitions taken from the ASCII table
#define AVATAR 'A'
#define WALL '*'
#define EMPTY_SPACE ' '


// 2D character array which the maze is mapped into
char MAZE[NUMROWS][NUMCOLS];


// POST: Generates a random maze structure into MAZE[][]
//You will want to use the rand() function and maybe use the output %100.  
//You will have to use the argument to the command line to determine how 
//difficult the maze is (how many maze characters are on the screen).
void generate_maze(int difficulty);

// PRE: MAZE[][] has been initialized by generate_maze()
// POST: Draws the maze to the screen 
void draw_maze(void);

// PRE: 0 < x < COLS, 0 < y < ROWS, 0 < use < 255
// POST: Draws character use to the screen and position x,y
void draw_character(int x, int y, char use);

// PRE: -1.0 < x_mag < 1.0
// POST: Returns tilt magnitude scaled to -1.0 -> 1.0
// You may want to reuse the roll function written in previous labs.  
float calc_roll(float x_mag);

// Main - Run with './ds4rd.exe -t -g -b' piped into STDIN
int main(int argc, char* argv[])
{
	if (argc <2) { printf("You forgot the difficulty\n"); return 1;}
	int difficulty = atoi(argv[1]); // get difficulty from first command line arg
	// setup screen    
	initscr();
	refresh();
	int Locx = NUMCOLS / 2, Locy = 0, prevLocy, prevLocx, time, prevTime = 0, lost = 0;
	float x_mag, y_mag, z_mag, roll;

	// Generate and draw the maze, with initial avatar
	//draws the character and maze by running the functions
	generate_maze(atoi(argv[1]));
	draw_maze();
	mvaddch(Locy, Locx, AVATAR);
	refresh();

	// Read gyroscope data to get ready for using moving averages.    

	// Event loop
	do
	{
		scanf("%d, %lf, %lf, %lf", time, x_mag, y_mag, z_mag);
		if((time-prevTime) > 100){
			
		// Read data, update average
			roll = calc_roll(x_mag);
		
			if((MAZE[Locy][Locx + 1] == WALL) && (MAZE[Locy][Locx - 1] == WALL) && (MAZE[Locy + 1][Locx] == WALL)){
				printf("You lost!");
				lost = 1;
			}
		// Is it time to move?  if so, then move avatar
		
			prevLocy = Locy;
			if(MAZE[Locy + 1][Locx] == EMPTY_SPACE){
				Locy++;
			}
			prevTime = time;
			
			prevLocx = Locx;
		if(roll > 0.3){
			if(!(Locx - 1 < 0)){
				if(MAZE[Locy][Locx-1] == EMPTY_SPACE){
					Locx--;
				}
			}
		}
		if(roll < -0.3){
			if(!(Locx + 2 > NUMCOLS)){
				if(MAZE[Locy][Locx + 1] == EMPTY_SPACE){
					Locx++;
				}
			}
		}
		}
			mvaddch(prevLocy, prevLocx, EMPTY_SPACE);
			mvaddch(Locy, Locx, AVATAR);
			refresh();
		//prints the win message if lose isn't true and when the character hits the bottom
	}while((Locy > NUMROWS - 1) && !(lost)); // Change this to end game at right time 

	// Print the win message
	endwin();
	
	printf("YOU WIN!\n");
	return 0;
}

// PRE: 0 < x < COLS, 0 < y < ROWS, 0 < use < 255
// POST: Draws character use to the screen and position x,y
//THIS CODE FUNCTIONS FOR PLACING THE AVATAR AS PROVIDED.
//
//    >>>>DO NOT CHANGE THIS FUNCTION.<<<<
void draw_character(int x, int y, char use){
	mvaddch(y,x,use);    
	refresh();
}

void generate_maze(int difficulty){
//makes the maze depending on the level of difficulty. Also decides when to put a wall or an empty space
	int i, j;
	for(i=0; i < NUMROWS; i++){
		for(j=0; j < NUMCOLS; j++){
			MAZE[i][j] = EMPTY_SPACE;
		}
	}
	
	for(i=0; i < NUMROWS; i++){
		for(j=0; j < NUMCOLS; j++){
			if((difficulty) >= ((rand() % 100) + 1)){
				MAZE[i][j] = WALL;
			}
		}
	}
}

void draw_maze(void){
//iterates through the MAZE array to print out the walls
	int i, j;
	for(i = 0; i < NUMROWS; i++){
		for(j = 0; j < NUMCOLS; j++){
			mvaddch(i,j,MAZE[i][j]);
			refresh();
		}
	}
}

float calc_roll(float x_mag){ //sets the x_mag input to either equal -1 or 1 depending on being negative or positive
	
	if(x_mag < -1.0){
		x_mag = -1.0;
	}
	if(x_mag > 1.0){
		x_mag = 1.0;
	}
	return x_mag;
}