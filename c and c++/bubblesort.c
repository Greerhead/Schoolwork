//bubble.c
//famous bubble sort
//implement the swap algorithm with pointers

#include <stdio.h>
#define MAX 9

//function prototypes
void printValues();
void sort();
void swap(int* pA, int* pB);
int values[] = {7, 3, 9, 4, 6, 1, 2, 8, 5};

int main(){
  int temp;
  printf("Before: \n");
  printValues();
  sort();
  printf("After: \n");
  printValues();
  return(0);
} // end main

void printValues(){
    int i;
    printf("[");

    for ( i = 0 ; i < MAX; i++){
        printf("%d" , values[i]);
    }//end for

    printf("]");
    printf("\n");
}//end printValues

void swap(int *pA, int *pB){
    int temp;
    temp = *pA;
    *pA = *pB;
    *pB = temp;
}//end swap

void sort(){
    int f;
    int j;
    for ( f = 0 ; f < MAX -1 ; f++){//for loop that tells how many times to run loop below
        for ( j = 0 ; j < MAX - 1; j++){//for loop that compares two values
            if (values[j] > values[j + 1]){//if that compares and then runs swap
                swap(&values[j], &values[j+1]);
                printValues();

            }//end if


        }//end for
    }//end for
}//end sort

