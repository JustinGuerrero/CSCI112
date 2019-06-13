//
// Created by Justin Guerrero on 4/10/2019.
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "student.h"
class_t classes[20];
void parseLine(class_t classes[], char* line){
    // parse line will utilize the strtok function to gather the
    // information necessary and only the necessary information
    // by splitting elements in the file by either spaces, or
    // commas.
    //*where we are gathering our information
    //
    char temp[81];
    char *result;
    int i = 0;

    result = strtok(line, " ");
    strcpy(classes[i].className, result);
    result= strtok(NULL, "$");
    strcpy(classes[i].classTitle, result);
    result = strtok(NULL, " ");
    strcpy(classes[i].classDays, result);
    result = strtok(NULL, " ");
    strcpy(classes[i].classTime, result);
    result = strtok(NULL, " ");
    classes[i].year = result[0];
    //printf(result);
    return;

}
