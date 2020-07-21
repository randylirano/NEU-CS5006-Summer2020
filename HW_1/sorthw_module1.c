/*
CS5006
Homework 1 - Sample solution
2020/07/07
Randy Lirano
*/

// This program is one alternative solution to selection sort implementation

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define LIMIT 100
#define RAND_RANGE 100

int source[LIMIT]; // array to hold input data values
int dest[LIMIT];   // array to hold sorted data values
bool valid[LIMIT]; // array that indicates which input values are valid

int i;             // loop variable
int j;             // loop variable
int smallest;      // current smallest element

int main(){
    // Seed random numbers
    srand((unsigned)time(NULL));

    //initialize valid array - at begining the full array is valid
    for (i=0; i<LIMIT; i++) {
        valid[i] = true;
    }

    //initialize source array with random number from 0..RAND_RANGE
    for (i=0; i<LIMIT; i++) {
        source[i] = rand() % RAND_RANGE;
    }

    //print out source array in rows of 20 elments
    printf("Source array:\n");
    for (i=0; i < ((LIMIT/20)+1); i++) {
        for (j=0; j<20; j++) {
            if (i*20+j < LIMIT) {
                printf("%.2d ",source[i*20+j]);
            }
        }
        printf("\n");
    }

    printf("\n");

    //selection sort
    for (i=0; i<LIMIT; i++) {
        // find first valid element of source array as the starting smallest
        smallest = LIMIT;
        for (j=0; j<LIMIT; j++) {
            if ((smallest == LIMIT) && valid[j]) {
                smallest = j;
            }
        }

        // check that we found a valid element
        if (smallest == LIMIT) {
            printf("\nERROR: could not find valid element in source array\n");
        }

        // compare all valid elements of array to find a new smallest element
        for (j=0; j<LIMIT; j++) {
            if (valid[j] && (source[j] < source[smallest])) {
                // found a new smallest
                smallest = j;
            }
        }

        // copy smallest to destination and make that source element invalid
        dest[i] = source[smallest];
        valid[smallest] = false;
    }

    //print out destination array in rows of 20
    printf("Destination array:\n");
    for (i=0; i < ((LIMIT/20)+1); i++) {
        for (j=0; j<20; j++) {
            if (i*20+j < LIMIT) {
                printf("%.2d ",dest[i*20+j]);
            }
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}
