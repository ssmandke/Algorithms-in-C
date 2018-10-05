#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>


#define N 5

char visited[N] = {0};

void dfs(char matrix[][N], char i)
{
  
  if(i>=N)
  {
    return;
  }
  
  char j = 0;
  
  visited[i] = 1;
  printf("%d ",i);
  for(j=0; j<N; j++)
   {
     if((visited[j]==0) && (matrix[i][j]==1))
     {
       dfs(matrix, j);
     }
   }
}

int main()
{
  char array[N][N] = {{1,0,0,1,0},{0,1,0,1,0},{1,1,1,1,0},{0,1,1,0,0},{0,0,0,0,1}};
  char i,j;
  
  for(i=0; i<N; i++)
  {
    for(j=0; j<N; j++)
	{
	   printf(" %d ", array[i][j]);
	}  
	printf("\r\n");
  }
	
  dfs(array,0);
}