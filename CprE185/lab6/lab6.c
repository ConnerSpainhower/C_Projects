// 185 lab6.c
//
// This is the outline for your program
// Please implement the functions given by the prototypes below and
// complete the main function to make the program complete.
// You must implement the functions which are prototyped below exactly
//  as they are requested.

#include <stdio.h>
#include <math.h>
#define PI 3.141592653589

//NO GLOBAL VARIABLES ALLOWED


//PRE: Arguments must point to double variables or int variables as appropriate
//This function scans a line of DS4 data, and returns
//  True when the square button is pressed
//  False Otherwise
//This function is the ONLY place scanf is allowed to be used
//POST: it modifies its arguments to return values read from the input line.
int read_line(double* g_x, double* g_y, double* g_z, int* time, int* Button_T, int* Button_X, int* Button_S, int* Button_C);
//doneish

// PRE: -1.0 <= x_mag <= 1.0
// This function computes the roll of the DS4 in radians
// if x_mag outside of -1 to 1, treat it as if it were -1 or 1
// POST: -PI/2 <= return value <= PI/2
double roll(double x_mag);
//doneish

// PRE: -1.0 <= y_mag <= 1.0
// This function computes the pitch of the DS4 in radians
// if y_mag outside of -1 to 1, treat it as if it were -1 or 1
// POST: -PI/2 <= return value <= PI/2
double pitch(double y_mag);
//doneish

// PRE: -PI/2 <= rad <= PI/2
// This function scales the roll value to fit on the screen
// POST: -39 <= return value <= 39
int scaleRadsForScreen(double rad);
//doneish

// PRE: num >= 0
// This function prints the character use to the screen num times
// This function is the ONLY place printf is allowed to be used
// POST: nothing is returned, but use has been printed num times
void print_chars(int num, char use);
//doneish

//PRE: -39 <= number <=39
// Uses print_chars to graph a number from -39 to 39 on the screen.
// You may assume that the screen is 80 characters wide.
void graph_line(int number);

int main()
{
	double x, y, z;                             // magnitude values of x, y, and z
	int b_Triangle, b_X, b_Square, b_Circle;    // variables to hold the button statuses
	double roll_rad, pitch_rad;                 // value of the roll measured in radians
	int scaled_value; 							// value of the roll adjusted to fit screen display
	int t, ax, ay, az, gx, gy, gz, b1, b2, b3, b4;

	//insert any beginning needed code here

	do
	{
		
		// Call read_line to get input
		read_line("%lf, %lf, %lf, %d, %d, %d, %d, %d", gx, gy, gz, t, b1, b2, b3, b4);

		// calculate roll and pitch.  Use the buttons to set the condition for roll and pitch
		if(b1 == 1){
			roll_rad = roll(x);
		}
		if(b3 == 1){
			pitch_rad = pitch(y);
		}
		// switch between roll and pitch(up vs. down button)

		// Scale your output value
	
		// Output your graph line
	
		fflush(stdout);
	} while (b_Square == 0); // Modify to stop when the square button is pressed
	return 0;
}


int read_line(double* g_x, double* g_y, double* g_z, int* time, int* Button_T, int* Button_X, int* Button_S, int* Button_C){
	
	scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d", &time, &g_x, &g_y, &g_z, &Button_T, &Button_X, &Button_S, &Button_C);
	
	if(*Button_C == 1){
		return 1;
}
	else{
		return 0;
	}
}

double roll(double x_mag){
	if(x_mag <= -1){
		x_mag = -PI/2;
		
	}
	else if(x_mag >= 1){
		x_mag = PI/2;
	}
	else{
		return 0;
	}
}

double pitch(double y_mag){
	if(y_mag <= -1){
		y_mag = -PI/2;
		
	}
	else if(y_mag >= 1){
		y_mag = PI/2;
	}
	else{
		return 0;
	}
}

int scaleRadsForScreen(double rad){
	while(rad >= -PI/2 && rad <= PI/2){
		if(rad >= -39 && rad <= 39){
			return rad;
		}
		else{
			return 0;
		}
	}
}

void print_chars(int num, char use){
	int i;
	for(i = 0; i <= num; i++){
		printf("%c", use);
	}
	fflush(stdout);
}
//NOTES
	//BUTTONS:
		//Square is b4
		//Cross is b3
		//Circle is b2
		//Triangle is b1
		
	//Geo:
		//PITCH: gz is almost -1 when straight up; opposite gets almost 1; approaches from positive to 0 when tipped forward; opposite when backward
		//gy is 1 when lying down, 1 when face down
		//ROLL: gx is -1 when to the right, 1 when to the left; 0 from negative right to left, opposite for left to right
	//Time:
		//In milliseconds; change to seconds