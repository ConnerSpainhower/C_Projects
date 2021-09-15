#include <stdio.h>
#include <math.h>


int close_to(double tolerance, double point, double value);
int close_to2(double tol, double poi, double val);
double distance(double time);
int seconds(int milliseconds);
double mag(double gx,double gy,double gz);
int count = 1;

int t, b1=0, b2, b3, b4, drop=0, done=1;
double gx, gy, gz, finT, msr;
int fallStrt, fallEnd;

int main(void) {
    
	int direction = 0;
	double var = 0.5;
	printf("<Conner> <Spainhower>\n<cspainho>\n");
	printf("Ok, I'm now receiving data.\nI'm Waiting");
	scanf("%d, %lf, %lf, %lf", &t, &gx, &gy, &gz);
	while(close_to(.3, mag(gx, gy, gz), 1.0)){
		scanf("%d, %lf, %lf, %lf", &t, &gx, &gy, &gz);
		if(count %10 == 0){
			printf(".");
			fflush(stdout);
			count = 1; 
		}
		count++; 
		//msr = mag(gx, gy, gz);
		//drop = (close_to(.2,1,msr)); //makes drop 1 if a drop is detected
	}
	
	
	fallStrt = t;
    while (mag(gx, gy, gz) < 2.0) {
		scanf("%d, %lf, %lf, %lf", &t, &gx, &gy, &gz);
		msr = mag(gx, gy, gz);
		//printf("%lf", msr);
		if(!b1){
			printf("\nHelp me! I'm falling!\n");
		}
		// scanf("%d, %lf, %lf, %lf", &t, &gx, &gy, &gz);
		b1++;
		if(b1 % 10 == 0){
			printf("!\n");
			fflush(stdout);
		}
		fflush(stdout);
		msr = mag(gx,gy,gz);
		done = msr < 2.0;    
	}
	
	fallEnd = t;
	finT = fallEnd - fallStrt;
	finT = finT / 1000.0;
	printf("\nI fell %lf meters in %lf seconds", distance(finT), finT); 
    return 0;
}

int close_to(double tolerance, double point, double value){
	if(fabs(value - point) <= tolerance){
		return 1;
}
else{
	return 0;
}
}

double mag(double gx,double gy,double gz){
			double magnitude = sqrt((gx * gx) + pow(gy,2) + pow(gz,2));
			//printf("%lf", magnitude);
			return magnitude;
}

int seconds(int t){
	int seconds = t / 1000;
	return seconds;
}

double distance(double time){
	double distance;
	distance = (0.5 * 9.8 * time * time);
	return distance;
}
