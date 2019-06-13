//
// Created by Justin Guerrero on 4/10/2019.
//

#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include<string.h>
#include "student.h"

// The below functions will sort the file by time, day and class number. they first use a for loop and store
// the sorted data insiide of the temp structure to be called when sorted.
class_t classes[20];
//char *day;
void sortbyclassnum(class_t classes[], int n, FILE* fptr){

    int i, j, doswap = 0;

   class_t temp;

    for (i = 0; i < n; ++i) {
        for (j = i; j < n; ++j) {
             doswap = strcmp(classes[i].className, classes[j].className);
            }
			
	if (doswap > 0) {
                temp = classes[i];
                classes[i]= classes[j];
                classes[j] = temp;
            }

 
        }
    
    return;

}

void sortbyclasstime(class_t classes[], int n, FILE* fptr){

    int i, j, doswap = 0;

   class_t temp;

    for (i = 0; i < n; ++i) {
        for (j = i; j < n; ++j) {
             doswap = strcmp(classes[i].classTime, classes[j].classTime);
            }

        if (doswap > 0) {
                temp = classes[i];
                classes[i]= classes[j];
                classes[j] = temp;
            }


        }
    
    return;
}
void sortbyclassdays(class_t classes[], int n, FILE* fptr){

    int i, j, doswap = 0;

    class_t temp;

    for (i = 0; i < n; ++i) {
        for (j = i; j < n; ++j) {
            doswap = strcmp(classes[i].classDays, classes[j].classDays);
        }

        if (doswap > 0) {
            temp = classes[i];
            classes[i]= classes[j];
            classes[j] = temp;
        }
    }

    return;
}
// the print statements below are what get called in the switch statement from queryUser, they
// decide what gets printed depending on the users input choice.
void printAllClasses(class_t classes[], int n, FILE* fptr){
	sortbyclassnum(classes, n, fptr);
	int i;
	for (i = 0; i < n; ++i) {
		printOneClass(classes[i], fptr);
		}
	fprintf(fptr,"\n");	
	
	return;
}

void printClassDay(class_t classDays[], char* day, int n, FILE* fptr){
    //this method will print classes by days selected by user
    sortbyclassdays(classes, n, fptr);
    for(int i = 0; i < n; ++i){
        if(strcmp(classDays[i].classDays, day) == 0){
            printOneClass(classDays[i], fptr);
		}
    
       

        
        else if(strcmp(classDays[i].classDays, day) == 0){
            printOneClass(classDays[i], fptr);
		}
	    
 	} 
        fprintf(fptr, "\n");
    
    return;
}

void printClassTime(class_t classTime[], char* day, char* time, int n, FILE* fptr) {
    // this method will print classes by a given time and day given by user
    sortbyclasstime(classes, n, fptr);
    sortbyclassdays(classes, n, fptr);
    for (int i = 0; i < n; ++i) {
	    if (strncmp(classTime[i].classTime, time, 4) == 0){
			if((strcmp(classTime[i].classDays, day) == 0)){
            			printOneClass(classTime[i], fptr);
				}
				
				
        		else if(strcmp(classTime[i].classDays, day) == 0){
           			 printOneClass(classTime[i], fptr);
					}
				

				 
        

        }
    }

    
    return;
}
void yearMethod(class_t classes[],char year, int n, FILE* fptr){
	int i = 0;
	// must sort class array by class number, which will pop out the numbers
	// by the given year level
	for (i = 0; i < n; ++i) {
		if (classes[i].year == year) {
			printOneClass(classes[i], fptr);
				}
			fprintf(fptr, "\n");

			
		
	}
	return;
}

void printOneClass(class_t class, FILE* fptr) {
	fprintf(fptr, "%-45s %s ", class.classTitle, class.className);
	switch(class.year) {
	case '1':
		fprintf(fptr, "Freshman ");
		break;

	case '2':
		fprintf(fptr, "Sophomore ");
		break;

        case '3':
                fprintf(fptr,"Junior  ");
                break;

        case '4':
                fprintf(fptr, "Senior ");
                break;


	// print format for each print statement.
	Default:
		printf("ERROR: bad year\n");
		exit(1);
	}
	fprintf(fptr, "%s %s\n", class.classDays, class.classTime);
	return;
}
