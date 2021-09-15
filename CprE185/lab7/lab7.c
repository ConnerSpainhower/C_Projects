// 185 Lab 7
#include <stdio.h>


#define MAXPOINTS 10000

// compute the average of the first num_items of buffer
double avg(double buffer[], int num_items);

//update the max and min of the first num_items of array
void maxmin(double array[], int num_items, double* max, double* min);

//shift length-1 elements of the buffer to the left and put the 
//new_item on the right.
void updatebuffer(double buffer[], int length, double new_item);



int main(int argc, char* argv[]) {
	
	/* DO NOT CHANGE THIS PART OF THE CODE */

	double x[MAXPOINTS], y[MAXPOINTS], z[MAXPOINTS];
	int lengthofavg = 0;
	if (argc>1) {
		sscanf(argv[1], "%d", &lengthofavg );
		printf("You entered a buffer length of %d\n", lengthofavg);
	}
	else {
		printf("Enter a length on the command line\n");
		return -1;
	}
	if (lengthofavg <1 || lengthofavg >MAXPOINTS) {
		printf("Invalid length\n");
		return -1;
	}

	do{
	
	/* PUT YOUR CODE HERE */
	
	
	}(while !
}




double avg(double buffer[], int num_items){
	double average = 0;
	int i;
	for (i = 0; i <= num_items; i++){
		average = (average + buffer[i]) / num_items;
	}
	return average;
}

void maxmin(double array[], int num_items, double* max, double* min){
	
	int j;
	for (j = 0; j <= num_items; j++){
		if(array[j] > array[j-1]){
			*max = array[j];
		}
		if(array[j] < array[j-1]){
			*min = array[j];
		}
	}
}

void updatebuffer(double buffer[], int length, double new_item){
	
	buffer[length] = buffer[length-1];
	buffer[length + 1] = new_item;
	
}