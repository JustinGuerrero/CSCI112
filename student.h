//
// Created by Justin Guerrero on 4/1/2019.
// Dot is passed by value, arrow is passed
// by reference
//
//
typedef struct{
    char className[80];   //name of student char array
    char classTitle[80];  // class title array
    char classDays[80];	  //class day array
    char classTime[80];
    char year;        // selection 1-4 for fresh-senior choice
} class_t;        // to make a user defined type stand out


// function declarations to give communication through the files.
int readClasses(class_t classes[], FILE* filepntr);
void parseLine(class_t classes[], char* line);
void queryUser(class_t classes[], int n);
void printAllClasses(class_t classes[], int n, FILE* filepntr);
void printClassDay(class_t classes[], char* day, int n, FILE* filepntr);
void printClassTime(class_t classes[], char* day, char* time, int n, FILE* filepntr);
void yearMethod(class_t classes[], char year, int n, FILE* filepntr);
void printOneClass(class_t class, FILE* filepntr);
void sortclassnum(class_t classes[], int n, FILE* filepntr);
void sortclasstime(class_t classes[], int n, FILE* filepntr);
