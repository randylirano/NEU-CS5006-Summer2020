#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define LIMIT 50
#define RAND_RANGE 100

int source[LIMIT]; // array to hold input data values

int i;             // loop variable
int j;             // loop variable


// take two subranges of the source array that are already sorted
// and merge them into a single sorted array range
void merge (int start, int midpoint, int stop) {
    int temp[LIMIT]; // temporary array
    int i;
    int Lindex;      // current value in left array subrange
    int Rindex;      // current value in the right array subrange
    int Sindex;      // current value in the source array range

    //copy data into temp array
    for (i=start; i<=stop; i++) {
        temp[i] = source[i];
    }

    // merge the arrays while there are still elements in both arrays
    Lindex = start;
    Rindex = midpoint+1;
    Sindex = start;
    while ((Lindex <= midpoint) && (Rindex <= stop)) {
        if (temp[Lindex] <= temp[Rindex]) {
            source[Sindex] = temp[Lindex];
            Lindex++;
        } else {
            source[Sindex] = temp[Rindex];
            Rindex++;
        }
        Sindex++;
    }

    // merge in remaining elements from the left array
    for (i=Lindex; i<=midpoint; i++) {
        source[Sindex] = temp[i];
        Sindex++;
    }

    // merge in remaining elements from the right array
    for (i=Rindex; i<=stop; i++) {
        source[Sindex] = temp[i];
        Sindex++;
    }

    return;
}

// break the range into two parts, sort the left and right, then merge them
void mergeSort (int start, int stop) {
    int midpoint;
    if (start < stop) {
        // break range into two parts
        midpoint = (start+stop)/2;

        // sort the array subranges
        mergeSort(start, midpoint);
        mergeSort(midpoint+1, stop);

        // merge the two array subranges
        merge(start, midpoint, stop);
    }

    return;
}

int main(){

    //seed random numbers
    srand((unsigned)time(NULL));

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

    //perform mergesort
    mergeSort(0,LIMIT-1);


    //print out sorted  array in rows of 20
    printf("Sorted array:\n");
    for (i=0; i < ((LIMIT/20)+1); i++) {
        for (j=0; j<20; j++) {
            if (i*20+j < LIMIT) {
                printf("%.2d ",source[i*20+j]);
            }
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}
