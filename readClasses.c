//
// Created by Justin Guerrero on 4/10/2019.
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "student.h"

class_t classes[20];
int readClasses(class_t classes[], FILE* filepntr){
    // this function will read in a file, and then read through it
    // while there are items in the list, it will parse through them
    // until we hit the end of file
 
    //fgets to read line
    int i = 0;
    char line[81];
    while(fgets(line, 80, filepntr)!= NULL){
        parseLine(&classes[i], line);
        ++i;
    }
    return i;
}

