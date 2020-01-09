#include<stdio.h>
#include<string.h>
// the three functions below are all very similar, and will use recursion to sort the letters given
// the first will print each character in the string taken from the command line
void recursion1Char(char* str){
	if(strlen(str) == 0){
		//creates a base case for the function
		return;
	}	
	else{
		printf("{%c}\n", str[0]);
		recursion1Char(str +1);
		return;
	}


}
//here in this function there has been an addition for a foor loop to iterate through the 
//string but still taking into account all the pair possibilities with the first letter
void recursion2Char(char* str){
        if(strlen(str) == 0){
        	return;
	}
        else{
		for(int i = 1; i < strlen(str);i++){
               		printf("{%c, %c}\n", str[0],str[i]);
		}
                recursion2Char(str + 1);
                return;
        }


}
// this function becomes a tad more complex with the addition of a nested for loop
// using our knowledge of matricies, we can grab all the possibilities of pairs while
// using recursion, and not getting doubles, or reuse of each letter.
void recursion3Char(char* str){
        if(strlen(str) == 0){
        	return;
	}
        
        else{
                for(int i = 1; i < strlen(str);i++){
			//printf("{%c, %c, %c}\n", str[0],str[i], str[i]);
                
			for(int j = i + 1; j < strlen(str); j++){
				printf("{%c, %c, %c}\n", str[0], str[i],str[j]);
		}
		}
                recursion3Char(str +1);
                return;
        }


}

int main(int argc, char **argv){
	//char string to be read in from the argument on the command line
	char *str = argv[1];	
	while(1){
		// if statement will throw error if command line
		// does not have an argument written
		if(argc != 2){
				printf("Please enter four characters on the command line\n");
				}
		// else statement to throw error if number of elements is not four.
		else if(strlen(argv[1]) != 4){
			printf("Error: Please enter only four character values\n");
			break;
		}	
		else{	
			// else statement to run given code
			//print statement for one element subs
			printf("one_ele_subs\n");
			printf("{\"%s\"}\n", str);
			recursion1Char(str);
			//print statement for two element subs
		       	printf("two_ele_subs\n");
                        printf("{\"%s\"}\n" ,str);
			recursion2Char(str);
			//print statement for three element subs
			printf("three_ele_subs\n");
                        printf("{\"%s\"}\n" ,str);
			recursion3Char(str);
		}

	return 0;

	}
}
