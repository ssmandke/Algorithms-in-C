
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX(a,b) (a>b? a:b)

#define N 7

int arr[N] = {1, 101, 2 ,3 , 100 ,14 , 5};
int LIS[N] = {0,  0,  0 ,0 ,  0  ,0 , 0};

int main()
{
  int i = 0;
  int j = 0;
  int maxSum = -1;
   
  for(i=0; i<N; i++)
  {
	  for(j=0; j<=i; j++)
	  {
		  if(arr[j] <= arr[i])
		  {			  
	        LIS[i]+=arr[j];
			maxSum = MAX(maxSum, LIS[i]);
		  }
	  }
  }
  printf("\r\nmax = %d\r\n", maxSum);
  for(i=0; i<N; i++)
  {
	  printf(" %d ", LIS[i]);
  }
  printf("\r\n");
  
  return 0;
}