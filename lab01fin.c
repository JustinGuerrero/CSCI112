#include<stdio.h>
#define milage 0.35   //This will be the milage conversion rate

//Justin Guerrero
//lab01 
//01/15/2019
//

int 
main(void){

	double miles = 0;
	double used = 0;
	double totalUsed = 0;
	//first we will drop a nice title message
	
	printf("Here is your milage calculator\n");

	//next create a function to ask the user how many miles they start with
	printf("Enter the current miles on odometer => ");
	scanf("%lf", &miles);   //scan for user imput

	printf("Enter the miles on the odometer after trip => "); //this will give us the difference of miles used

	scanf("%lf", &used);

	totalUsed = used - miles;  //a function to tell how many miles were used during the trip
	printf("You traveled ");
	printf("%.2lf", totalUsed);
	printf(" miles at $0.35 per mile\n"); 

	double compensation = totalUsed * milage;  //subtract and multiply
	printf("your reimbursement is $");
	printf("%.2lf\n", compensation);

	return(0);
}

	


