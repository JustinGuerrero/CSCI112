#include<stdio.h>
#include<math.h>

// Here we will start the void statement required by Dr. Cummings.
void computeBMI(double weight,double height){
	// Create variables to grab the input from the user from our main function.
	double calcweight = weight;
	double calcheight = height;
	
	
	//here we will define how to compute BMI using the math library for the power
	double BMI;
	int num = 703;
	BMI = ((num * calcweight)/pow(calcheight, 2));


	// call the calculating function
	// and describe the parameters of the Standard weight recommendation.
	double underweight, normal, overweight;
	underweight = 18.5;
	normal = 24.9;
	overweight = 29.9;
	//The if statements listed below will determine what the person is. 
	// the first will take care of unrealistic (negative) numbers
	if(BMI < 0){
		printf("ERROR: Cannot process negative BMI, please enter valid data and try again\n");
	}

	else if(BMI <= underweight){
		printf("your BMI is %.2lf, which classifies as Underweight, eat cheeseburgers\n", BMI);
	}
	
	else if (BMI <= normal){
		printf("Your BMI is %.2lf, which is normal, keep up the good work\n", BMI); 
	}
	
	else if (BMI <= overweight){
		printf("Your BMI is %.2lf, which is classified as overweight, maybe consider going to the gym\n", BMI);
	}
	
	else{
		printf("Your BMI is %.2lf, which is clsasified as obese, we should consider some life changes\n",BMI);
	
	}

}
int main(void){
	double weight = 0;
	double height = 0;
	//The print and scanners are built here in the main function for
	//taking in user input for weight and height

	printf("Please enter your weight in pounds: ");
	scanf("%lf", &weight);
	printf("Please enter your height in inches: ");
	scanf("%lf", &height);
	

	
	computeBMI(weight, height);
	return(0);

}


	// BMI will be calculated in the function below
