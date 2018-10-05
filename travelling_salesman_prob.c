#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>


#define N 4
#define VISITED 1
#define NOT_VISITED 0
#define MIN(a,b) (a<b? a:b)
#define MAX(a,b) (a>b? a:b)

#if 0
char graph[][N] = \
{
	{0, 10, 15, 20},
	{5, 0,  9,  10},
	{6, 13, 0,  12},
	{8, 8, 9, 0}
};
#else
char graph[][N] = \
{
	{0, 4,  1, 3},
	{4, 0,  2, 1},
	{1, 2, 0,  5},
	{3, 1 , 5, 0}
};
#endif
char visited[N]={0};
char costSoFar = 0;

char findMinNextCity(char currentCity)
{
	int minDist = 999;
	int minVertex = -1;
	int temp;
	int i = 0;
	
	for(i=0; i<N; i++)
	{
		if((graph[currentCity][i]!=0) && (visited[i]== NOT_VISITED))
		{
			if(graph[currentCity][i] < minDist)
			{
				minDist = graph[i][0]+graph[currentCity][i]; //distance from current city to i and from i to origin..
			    temp = graph[currentCity][i];
			    minVertex = i;				
			}
		}
	}

	if(minDist !=999)
	{
		costSoFar = costSoFar + temp;
		//printf("curr %d to %d  cost = %d\r\n",currentCity,minVertex,costSoFar);
	}
	
	return minVertex;
}

void minimum_cost(int city)
{
	int nearest_city; //minVertex
	visited[city] = VISITED;
	printf(" %d ", city+1);
	nearest_city = findMinNextCity(city);
	
	if(nearest_city == -1)
	{
		nearest_city = 0;
		printf(" %d ", nearest_city+1);
		costSoFar = costSoFar + graph[city][nearest_city];
		return;
	}
	
	minimum_cost(nearest_city);
}

int main()
{
  int i = 0;
  int j = 0;
  
  for(i=0;i<N;i++)
  {
	  printf(" visited[%d] = %d --> ",i,visited[i]);
	  for(j=0;j<N;j++)
	  {
		  printf(" %d ",graph[i][j]);
	  }
	  printf("\r\n");
  }
  minimum_cost(0);
  return 0;
}