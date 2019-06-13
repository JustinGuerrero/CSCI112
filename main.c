#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "student.h"


int main(int argc, char **argv){

    class_t classes[20];
    FILE* filepntr = fopen("/public/csci112sp19/pgm1/classes.txt", "r");
    // The above will open the file that we read from
    // below we will call query user to find out what the
    // user wants to do.
    // the queryUser method calls up to a switch statement
    // that will call one of the other methods
    int n = readClasses(classes, filepntr);
    queryUser(classes, n);
    fclose(filepntr);
    return 0;
}

