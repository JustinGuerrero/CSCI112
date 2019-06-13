#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//make data structure for z data

typedef struct{
	int xx, 
	    yy,
	    zz,
	    mm;
	char name[80];
}address_t;
// declaring the functions at the top of the file to reach them.

int parseFile(address_t*, FILE*);
void compareIP(address_t*, int);
int parseFile(address_t IP[], FILE *fptr){
// this function will parse through the file and capture data
// into each element of the data structure. which will help us
// in our comparing functions	
    int i = 0;
    char line[81];
    char *result;
    while(fgets(line, 80, fptr)!= NULL){  	
	    result = strtok(line, ".");
	    sscanf(result, "%d", &IP[i].xx);
	    result= strtok(NULL, ".");
	    sscanf(result, "%d", &IP[i].yy);
	    result = strtok(NULL, ".");
	    sscanf(result, "%d", &IP[i].zz);
	    result = strtok(NULL, " ");
	    sscanf(result, "%d", &IP[i].mm);
	    result = strtok(NULL, "\n");
	    strcpy(IP[i].name, result);
	    i++;
    }
    // call the compare function to compare the data read in through
    // the parse function
    compareIP(IP, i);
    return i;

}

// here we have the compare function which will read the data, compare to see
// if the first two sets of digits are the same, if so the data will print to 
// the output file and give up the name of the addresses operating on the same network

void compareIP(address_t arr[], int n){
	FILE* out = fopen("outdata.txt", "w");
	fprintf(out, "Local Machines: \n");
	for(int i = 0; i < n; ++i){
		for(int j = i; j < n; ++j){
			if(arr[i].xx == arr[j].xx && arr[i].yy == arr[j].yy && i != j){
				fprintf(out, "Machine %s and %s are on the same locl network\n", arr[i].name, arr[j].name);
			}

		}
	}
	fprintf(out, "\n\n");
	for(int i = 0; i < n; i++){
		fprintf(out,"%d.%d.%d.%d %s\n", arr[i].xx, arr[i].yy, arr[i].zz, arr[i].mm, arr[i].name);
	}
	fclose(out);
	return;

}

// main will set up out structure, open the file, and call the parse file to start
// the program, and after it will close the file and away it goes.
int main(int argc, char** argv){
	address_t addresses[20];
	FILE* fptr = fopen("ipaddresses.txt", "r");
	parseFile(addresses, fptr);
	fclose(fptr);
	return 0;
}





