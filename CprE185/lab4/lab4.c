/*-----------------------------------------------------------------------------
-					         SE/CprE 185 Lab 04
-             Developed for 185-Rursch by T.Tran and K.Wang
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
-	                            Includes
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>


/*-----------------------------------------------------------------------------
-	                            Defines
-----------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------
-	                            Prototypes
-----------------------------------------------------------------------------*/
int close_to(double tolerance, double point, double value);
int close_to2(double tol, double poi, double val);

/*-----------------------------------------------------------------------------
-							  Implementation
-----------------------------------------------------------------------------*/
int main(void) {
    int t, b1, b2, b3, b4;
    double ax, ay, az, gx, gy, gz;
	int count = 0;
	int direction = 0;


    while (1) {
        scanf("%d, %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d", &t, &ax, &ay, &az, &gx, &gy, &gz, &b1, &b2, &b3, &b4 );
		if(count%100 == 0){
			if(close_to(.25,gy,.75) && direction != 1){
				printf("TOP\n");
				direction = 1;
			}
			else if(close_to(.25,gx,.75) && direction != 2){
				printf("RIGHT\n");
				direction = 2;
			}
			else if(close_to2(.25,gx,.75) && direction != 3){
				printf("LEFT\n");
				direction = 3;
			}
			else if(close_to2(.25,gy,.75) && direction != 4){
				printf("BOTTOM\n");
				direction = 4;
			}
			else if(close_to2(.25,gz,.75) && direction != 5){
				printf("FRONT\n");
				direction = 5;
			}
			else if(close_to(.25,gz,.9) && direction != 6){
				printf("BACK\n");
				direction = 6;
			}
			else if(b1 == 1){
				break;
			}
        // printf for observing values scanned in from ds4rd.exe, be sure to comment or remove in final program */
     // printf("Echoing output: %d, %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d \n", t, ax, ay, az, gx, gy, gz, b1, b2, b3, b4);
		}
		count++;
        /* It would be wise (mainly save time) if you copy your code to calculate the magnitude from last week
         (lab 3).  You will also need to copy your prototypes and functions to the appropriate sections
         in this program. */

        //printf("At %d ms, the acceleration's magnitude was: %f\n", t, mag(ax, ay, az));
	
    }

    return 0;
}

/* Put your functions here */
int close_to(double tolerance, double point, double value){
	if((value - point) <= tolerance){
		return 1;
}
}
int close_to2(double tol, double poi, double val){
	if((val + poi) <= tol){
		return 1;
}
}

double mag(double ax,double ay,double az){
			double magnitude = sqrt(pow(ax,2) + pow(ay,2) + pow(az,2));
			return magnitude;
}
