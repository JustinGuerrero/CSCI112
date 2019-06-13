//Justin Guerrero
//lab05
//CSCI 112
//Dr. Maryann Cummings
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// fact_calcoolater declares the factorial math inside of a for loop, and 
// new_pointer will store all the values given by our factorial calculator.
// The sprintf feature prints them to the new_pointer and strcat will
// add them to the len_plus string called in the parameter which you'll see
// below
void fact_calcoolater(char* len_plus, int num){
	int i;
	int factorial = 1;
	char* new_pointer = (char*) malloc(sizeof(char) * 80); 
	sprintf(new_pointer, "%d! = ", num);
	strcat(len_plus, new_pointer);
	for (i = num; i > 1 && i < 10; i--){
		
		factorial *= i;
	//	printf("%d X ", i);
		sprintf(new_pointer, "%d X ", i);
		strcat(len_plus, new_pointer);
		
	}
	sprintf(new_pointer, "%d", i);
	strcat(len_plus, new_pointer);
	sprintf(new_pointer, " = %d", factorial);
	strcat(len_plus, new_pointer);
}

// Here in the main function we declare our len_plus array and our ast array
// len will store like stated above all the values concatinated by our fact
// function. The while loop states while true we will run our program,
// breaking with a -1, and only allowing numbers between 0 and 9.
// finally below you will see the call for the function and then bam
// prints the stuff.
int main(void){
	char* asterisk = "*****************************************************";
	char* ast = (char*) malloc(sizeof(char) * 80);
	char* len_plus = (char*) malloc(sizeof(char) * 80);
	int num;
	

	while(1){
		printf("enter a number, -1 to quit\n");
		scanf("%d", &num);


		

		if (num == -1){
			break;
		}
		else if (num >= 10){
			printf("ERROR: size too large. Please enter integers 0-9\n");
		}else{

		memset(len_plus, '\0', 80);
		fact_calcoolater(len_plus, num);
		strncpy(ast, asterisk, strlen(len_plus) + 4);
		printf("%s \n", ast);
		printf("* %s *\n", len_plus);
		printf(ast);
		printf("\n");
		}
	}
	return 0;
}

