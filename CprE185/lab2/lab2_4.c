#include <stdio.h>
#include <math.h>
int main ()
{
	int a = 6427 + 1725;
	int b = (6971 * 3925) -95;
	double c = 79 +12/5;
	double d = 3640.0/107.9;
	int e = (22/3) * 3;
	int f = 22/(3 * 3);
	double g = 22/(3*3);
	double h = 22/3*3;
	double i = (22.0/3) * 3.0;
	int j = 22.0/(3*3.0);
	double k = 22.0/3.0*3.0;
	
	printf("%d\n%d\n%lf\n%lf\n%d\n%d\n%lf\n%lf\n%lf\n%d\n%lf\n", a, b, c, d, e, f, g, h, i, j, k);
	double area = pow(23.567,2)/(4*3.1415);
	printf("The area of a circle with a circumference of 23.567 is: %.2lf\n", area);
	double FTtoM = (14*0.3);
	printf("14 feet to meters is: %d\n", FTtoM);
	double FtoC = ((76-32)/1.8);
	printf("76 degrees Fahrenheit to Celsius is: %.2lf\n", FtoC);
	//some values output differently due to the variable type. If it is an int, it won't output the exact answer
	//if the equation is a double, it will output a more exact answer
	return 0;
}