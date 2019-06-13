#include<stdio.h>
#include<math.h>


//The first function get corners will read in from a redirected file
double get_corners(double X[],double Y[]){

	int i = 0, no_items;
	do {
		no_items = scanf("%le %le", &X[i], &Y[i]);
		i++;
		//j++;

	} while (no_items > 0);
	i--;
	return(i);
}


// output corners is our print formatted for what's inside the file.
void output_corners(double X[], double Y[], int n){
	printf("X \t Y\n");
	printf("-------------\n");
	for (int i = 0; i < n; i++){
		printf("%.2lf \t %.2lf\n", X[i], Y[i]);

	}
	return;

}

double polygon_area(double X[], double Y[], int n){
	//Initialize the area variable
	double area = 0.0;

	// calculate using for loop for each point
	for (int i = 0; i < n - 2; i++){
		//printf("%.2lf x %.2lf y \n", X[i], Y[i]);
		area += (X[i+1] + X[i]) * (Y[i+1] - Y[i]);
		}
	// calculate and return the final answer 
	double result = fabs(area) /( 2.0);
	printf("area of this beast is %.2lf\n", result);
	return result;
}



int main(void){
	// Declare arrays to connect to parameters, and call each function.
	// arrays have 200 open spaces.
	double arr[200];
	double arr2[200];
	double n = get_corners(arr, arr2);
	output_corners(arr, arr2, n);
	polygon_area(arr, arr2, n);
	
	
}
