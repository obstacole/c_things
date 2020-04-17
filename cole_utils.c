/*
      *  Cole's C Utility Functions and Notes *

  Created by: Cole McReynolds
  Date Last Updated: 04/17/2020

  The purpoose of this code is to provide some common untility functions that
  I frequently use and keep having to rewrite. I also wanted to keep track of
  other common libraries, have a place to test code, and take notes on other
  functions I've learned over the years.

  If you use my code in your own project, please reference me in your README!
  Thanks!

*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
// #include <cmocka.h> // on the cse server
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

// make a test makefile

/*
  printArray(int array, int sizeOfArray)

  A dumb function for printing out an array easily. I wish C had easy generics
  and I could implement it generically, but NOPE.
*/
void printArray(int *arr, int size) {
  // check for NULL pointer
  if(arr == NULL) {
    printf("[NULL]\n");
    return;
  }

  if(size == 0) {
    printf("[]\n");
    return;
  }

  if(size == 1) {
    printf("[%d]\n", arr[0]);
    return;
  }

  int i = 0; // for non-C99 compilation
  printf("[%d, ", arr[i]);
  for(i = 1; i < size - 1; i++) {
    printf("%d, ", arr[i]);
  }
  printf("%d]\n", arr[size - 1]);

  return;
}

/*
  printArray(int array, int sizeOfArray

  A dumb function for printing out an array easily. I wish C had easy generics
  and I could implement it generically, but NOPE.
*/
void printMatrix(int **matrix, int x, int y) {
  // check for NULL pointer
  if(matrix == NULL) {
    printf("[NULL]\n");
    return;
  }

  if(x == 0 || y == 0) {
    printf("||\n");
    return;
  }

  int i, j; // for non-C99 compilation
  for(i = 0; i < x; i++) {
    printf("|");
    for(j = 0; j < y - 1; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("%d|\n", matrix[i][y-1]);
  }

  return;
}



/*
  buildMatrix_int(int width, int height)

  A matrix utility functin that allocates memory for a dynamic integer matrix
*/
int **buildMatrix_int(int x, int y) {
  int i = 0;
  int **matrix = (int **) malloc(sizeof(int *) * x);
  for(i = 0; i < y; i++) {
    matrix[i] = (int *) malloc(sizeof(int) * y);
  }
  return matrix;
}


/*
  buildMatrix_char(int width, int height)

  A matrix utility functin that allocates memory for a dynamic character matrix
*/
int **buildMatrix_int(int x, int y) {
  int i = 0;
  char **matrix = (char **) malloc(sizeof(char *) * x);
  for(i = 0; i < y; i++) {
    matrix[i] = (char *) malloc(sizeof(char) * y);
  }
  return matrix;
}




// int main() {
//   int **matrix = buildMatrix_int(0, 0);
//   // matrix[0][0] = 74;
//   // matrix[0][1] = 90;
//   // matrix[1][0] = 87;
//   // matrix[1][1] = 86;
//
//   int i = 0;
//   int j = 0;
//   printMatrix(matrix, i , j);
//
//
//   return 0;
// }
