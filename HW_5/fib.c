/*
CS5006
Homework 5 - Problem 1: Memoization Fibonacci
2020/08/04
Randy Lirano
*/

// This program calculate the nth number in the fibonacci sequence.

// Utility import
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

// max number of inputs
#define MAX_FIB 200

// result of call to fib function
unsigned long long result;

//loop variable
int i;


// ========================== MEMO DEFINITIONS ==========================

unsigned long long memo[MAX_FIB];     // array to hold computed data values
bool valid[MAX_FIB];                  // array to hold validity of data

// make all entries in the memoization table invalid
void initMemo() {
    for (int j = 0; j < MAX_FIB; j++) {
        memo[j] = 0;
        valid[j] = false;
    }

    return;
}

// ========================== TIME DEFINITIONS ==========================
// timer functions found in time.h
// time_t is time type
time_t startTime;
time_t stopTime;

// get current time in seconds from some magic date with
// t = time(NULL);
// or
// time(&t);
// where t is of type time_t
//
// get difference in secs between times (t1-t2) with
// d = difftime(t1, t2);
// where d is of type double

// ========================== NAIVE FIB  ==========================

unsigned long long fib(int n) {
    if (n < 1) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fib(n-2) + fib(n-1);
    }
}


// ========================== MEMOIZED FIB  ==========================

unsigned long long mfib(int n) {

    if (n == 0) {
        memo[n] = 0;
        valid[n] = true;
    } else if (n == 1) {
        memo[0] = 0;
        memo[1] = 1;
        valid[0] = true;
        valid[1] = true;
    } else {
        memo[0] = 0;
        memo[1] = 1;
        valid[0] = true;
        valid[1] = true;

        for (int k = 2; k <= n; k++) {
            memo[k] = memo[k - 1] + memo[k - 2];
            valid[k] = true;
        }
    }

    return memo[n];

}

// ========================== MAIN PROGRAM  ==========================
int main() {

    // for (i = 0; i < 55; i+=5) {
    //     // get start time
    //     time(&startTime);
    //     // call fib
    //     result = fib(i);
    //     // get stop time
    //     time(&stopTime);
    //
    //     printf("fib of %d = %llu\n", i, result);
    //     printf("time taken (sec) = %lf\n\n", difftime(stopTime, startTime));
    // }
    //
    // printf("\n\n\n");

    for (i = 0; i < 90; i+=5) {
        // get start time
        time(&startTime);
        // call mfib
        initMemo();
        result = mfib(i);
        // get stop time
        time(&stopTime);

        printf("mfib of %d = %llu\n", i, result);
        printf("time taken (sec) = %lf\n\n", difftime(stopTime, startTime));
    }

    return 0;
}
