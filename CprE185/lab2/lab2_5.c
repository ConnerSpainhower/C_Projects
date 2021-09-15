/*-----------------------------------------------------------------------------
-					          CPRE 185 Lab 02
-	Name: Conner Spainhower
- 	Section: 9
-	NetID: cspainho
-	Date: 9/11/19
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


/*-----------------------------------------------------------------------------
-							 Implementation
-----------------------------------------------------------------------------*/
int main()
{
    double a, b, c;
    double filler;
    /* Put your code after this line */
	printf("Enter a value for a: ");
	scanf("%lf", &a);
	printf("Enter a value for b: ");
	scanf("%lf", &b);
	double equation = pow(a,2) + pow(b,2);
	

    /*  This next line will calculate the square root of whatever value is
        inside the parenthesis and assigns it to the variable filler. */
    filler = sqrt(equation);
	printf("The value of c is, %lf", filler);



    return 0;


}

