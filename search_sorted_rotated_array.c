#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include<string.h>

#define true 1
#define false 0
#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)

#define NUM_ELEM 8 
             //0  1  2   3   4   5  6  7
int array[] = {7, 8, 17, 19, 21, 1, 2 ,3};

void printArray()
{
	int i = 0;
	for(i =0; i< NUM_ELEM; i++)
	{
		printf(" %d ", array[i]);
	}
	
	printf("\r\n");
}
int rotated_binary_search(int A[], int N, int key) {
  int L = 0;
  int R = N - 1;
 
  while (L <= R) {
    // Avoid overflow, same as M=(L+R)/2
    int M = L + ((R - L) / 2);
    if (A[M] == key) return M;
 
    // the bottom half is sorted
    if (A[L] <= A[M]) {
      if (A[L] <= key && key < A[M])
        R = M - 1;
      else
        L = M + 1;
    }
    // the upper half is sorted
    else {
      if (A[M] < key && key <= A[R])
        L = M + 1;
      else 
        R = M - 1;
    }
  }
  return -1;
}
int main()
{
	int idx = rotated_binary_search(array,  NUM_ELEM, 1);
	printf("index of 1 = %d\r\n\r\n", idx);
	idx = rotated_binary_search(array, NUM_ELEM, 21);
	printf("index of 21 = %d\r\n", idx);
	idx = rotated_binary_search(array,  NUM_ELEM, 7);
	printf("index of 7 = %d\r\n", idx);	
	idx = rotated_binary_search(array,  NUM_ELEM, 17);
	printf("index of 17 = %d\r\n", idx);		
	return 0;
}