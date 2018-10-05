#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>


char array[] = {16, 3, 5, 19, 10, 14, 12, 0, 15};

//LIS..
//we go from left to right..check if the next number is extending previous seq..given that it should be > prev element
//else we check if current subsequence is ok and retain that as longest..

#define MAX(a,b) (a>b?a:b)

void LIS_check(char arr[], char len)
{  
  int i = 0;
  int j = 0; // given that we are traversing different lengths in array for every iteration..
  int *LIS = malloc(sizeof(int) * len); // placeholder for LIS..
  int LISMax = 0;//global maximum from LIS array...
  printf("\r\nLISMax = %d, sizeof LIS array  = %d\r\n", LISMax,sizeof(LIS));
  
  for(i=0 ; i<len; i++)
  {
	  LIS[i] = 0;
  }
  
  for(i=0 ; i<len; i++)
  {
    for(j=0; j<i; j++)
    {
       if((LIS[j] + 1 > LIS[i]) && (arr[j] < arr[i]))
       {
          LIS[i] = LIS[j]+1;
          LISMax = MAX(LISMax, LIS[i]);
		  printf("\r\nLISMax = %d\r\n", LISMax);
       }
    }
  }
  printf("\r\nLISMax = %d\r\n", LISMax);
}

int main()
{
	LIS_check(array, sizeof(array)/sizeof(char));
	return 0;
}