#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a,b) (a>b? a: b)

char array[] = {-2, -3, 4, -1, -2, 1, 5, -3};

void maxSumSubArray(char arr[], char len)
{
  char maxEndingSoFar = 0;
  char maxEndingHere = 0;

  int i = 0;
  
  for(i=0; i<len; i++)
  {
	  maxEndingHere = maxEndingHere + arr[i];
	  maxEndingSoFar = MAX(maxEndingHere, maxEndingSoFar);
	  
	  if(maxEndingHere < 0)
		  maxEndingHere = 0;
  }
  
  printf(" %d \r\n", maxEndingSoFar);

}

int main()
{
  maxSumSubArray(array, sizeof(array)/sizeof(char));
  return 0;
}