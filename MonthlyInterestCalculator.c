#include<stdio.h>
#include<math.h>

void calculateMonthlyPayment(int principal, int term, double interest){
	// principal = principal
	// monthly interest rate = interest
	// total number of payemt = term
	//determine the monthly interest by dividing the interest by 12
	//and then by 100
	interest = (interest/12)/100;

	// declare a function to calculate payment	
	double payment = (interest * principal)/(1-pow((1+interest),-term));
	printf("your monthly payment is %.2lf.  \n", payment);
	printf("Principal ""\t","\t","\t","%.2lf \n", principal);
	printf("Interest " "\t", "%.2lf", "\t", "Term", "%d", interest, term);
}
int main(int argc, char** argv){
	// declare variables to pass through to the function
	int principal;
	int term;
	double interest;
	
	//sscanf(argv[1], "%lf", &principal);
	//sscanf(argv[2], "%d", &term);
	//sscanf(argv[3], "%lf", &interest);	
	// ask the user to input the term, amount, etc
	printf("How much would you like to borrow? \n");
	scanf("%d", &principal);

	printf("please enter how many months you wish to take out on the loan\n");
	scanf("%d", &term);
	

	printf("What is your interest amount?\n");
	scanf("%lf", &interest);
	
	// call the function to the main.
	calculateMonthlyPayment(principal, term, interest);
	return 0;
}
