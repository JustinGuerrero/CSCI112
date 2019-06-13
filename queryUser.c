
#include<stdio.h>
#include<string.h>
#include "student.h"
class_t classes[20];


void queryUser(class_t classes[], int n){
    // This will prompt the user what they would like to do within the program
    // the idea here is to decide how each function needs to run
    char year;
    char user = 'a';
    char time[80];
    char day[80];
    char nl;
    // FILE* iptr = fopen("/public/csci112sp19/pgm1/classes.txt", "r");	
    FILE* fptr = fopen("out.txt", "w");
    while(user != 'Q'){
        printf("\nWhat would you like to do? Please use capital letters\n");
        printf("A - Print all classes\n");
        printf("B - Print all classes by day\n");
        printf("C - Print Classes by time and day\n");
        printf("D - Print all classes for student year\n");
        printf("Q - Quit\n");
        scanf("%c%c", &user, &nl);

    
        // there will be an switch case statement in this function
        // similar to if statements, if a case is called
        // the function will dictate what will print the information
        // stored in the selected array
        // put lower case in also
printf("user is %c and n is %d\n", user, n);
        switch(user){
            case 'A':
                printAllClasses(classes, n,fptr);
                break;

            case 'B':
                printf("What days would you like to sort by MWF or TR? \n");
                scanf("%s", day);
		scanf("%c", &nl);
                printClassDay(classes, day , n, fptr);
                break;
            case 'C':
                printf("what time would like to sort by, use 4 digit time \n");
                scanf("%s", time);
		printf("What day would you like to sort by(MWF or TR)\n");
		scanf("%s", day);
		scanf("%c", &nl);
                printClassTime(classes, day, time, n, fptr);
                //search array for day and time matching
                break;
            case 'D':
                printf("Please enter what year in school, Fresh: 1, Soph: 2, JR: 3, SR, 4\n");

                scanf("%c", &year);
		scanf("%c", &nl);
                yearMethod(classes, year, n, fptr);
                break;
            case 'Q':
                break;
            default:
                printf("Please use capital letters\n");
        }
    }
}

