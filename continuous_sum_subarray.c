
//continuous sum subarray

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define N 5//7
#define DIVISOR 6
#define MIN(a,b) (a<b? a:b)
#define MAX(a,b) (a>b? a:b)

char array[] = {23, 2, 4, 6, 5};//{23, 2 ,3 ,4 ,7 ,8 ,11};

int main()
{
  int i,j,k;
  int tmpSum = 0;
  int tmpCount = 0;
  int maxCount = 0;
  
  int maxEndingSoFar = 0;
  int maxEndingHere  = 0;

  for(i=0; i<N; i++)
  {
    for(j=i; j<N; j++)
    {
      tmpSum = 0;
      tmpCount = 0;

      for(k=i; k<=j ; k++)
      {
        printf(" %d ", k);
        tmpSum+=array[k];
        tmpCount++;
      }
      if(tmpSum % DIVISOR == 0)
      {
        maxCount = MAX(maxCount, tmpCount);       
      }
      printf("\r\n");
    }
  }
  printf(" maxCount = %d\r\n",maxCount);
  
  //Using Kadane..
  for(i=0; i<N; i++)
  {
	  maxEndingHere = MAX(array[i],maxEndingHere + array[i]);
	  maxEndingSoFar = MAX(maxEndingSoFar,maxEndingHere);	

      maxEndingHere = MAX(maxEndingHere, 0);
  }
  printf("\r\nMax Sum subarray total = %d\r\n",maxEndingSoFar);
  return 0;
}