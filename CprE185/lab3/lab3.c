/* 185 Lab 3 Template */

#include <stdio.h>
#include <math.h>

/* Put your function prototypes here */
double mag(double ax, double ay, double az);
int seconds(int t);
int minutes(int seconds);
int millis(int t);


int main(void) {
    /* DO NOT MODIFY THESE VARIABLE DECLARATIONS */
    int t;
    double  ax, ay, az;

    /* This while loop makes your code repeat. Don't get rid of it. */
    while (1) {
        scanf("%d,%lf,%lf,%lf", &t, &ax, &ay, &az); 

/* CODE SECTION 0 */
	//double s = t / 1000.0;
    //    printf("Echoing output: %00.3lf, %000.4lf, %000.4lf, %000.4lf\n", s, ax, ay, az);

/* CODE SECTION 1 */
	//	printf("At %d ms, the acceleration's magnitude was: %lf\n", 
      //      t, mag(ax, ay, az)); 
            
/* CODE SECTION 2 */
        printf("At %d minutes, %d seconds, and %d milliseconds it was: %lf\n", 
        minutes(t), seconds(t), millis(t), mag(ax,ay,az));
	
    }

return 0;
}

/* Put your functions here */
double mag(double ax,double ay,double az){
			double magnitude = sqrt(pow(ax,2) + pow(ay,2) + pow(az,2));
			return magnitude;
		}
int seconds(int t){
	int seconds = t / 1000;
	return seconds;
}
int minutes(int seconds){
	int min = seconds / 60000;
	return min;
	}
int millis(int t){
	int ms = t - ((t / 60000) - (t / 1000));
	return ms;
}
