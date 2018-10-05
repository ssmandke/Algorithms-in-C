
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define N 7
#define MIN(a,b) (a<b? a:b)
#define MAX(a,b) (a>b? a:b)

char dp_matrix[N][N];
char array[] ={23,2 ,3 ,4 ,7, 8, 13};

int main()
{
  int i,j,k;
  int tmpCount = 0;
  int maxCount = 0;
  int maxSum = 0;

  for(i=0; i<N; i++)
  {
    for(j=0; j<N; j++)
    {
      dp_matrix[i][j] = 0;
    }    
  }

  for(i=0 ;i<N; i++)
  {    
    dp_matrix[i][i] = array[i];
    tmpCount = 0;

    for(j=i+1; j<N; j++)
    {
		dp_matrix[i][j]=dp_matrix[i][j-1] + array[j];  

        tmpCount++;

        if(dp_matrix[i][j] %6 == 0)
        {
           maxCount = MAX(tmpCount, maxCount);
		   maxSum = MAX(maxSum,dp_matrix[i][j]);
        }              
    }
  }
  
  for(i=0; i<N; i++)
  {
    for(j=0; j<N; j++)
    {
		printf(" %d ",dp_matrix[i][j]);
	}
	printf("\r\n");
  }
  printf("\r\nContinous sum subarray => Sum = %d, numElements = %d\r\n",maxSum,maxCount);
  return 0;
}