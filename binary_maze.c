
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define CHAR_BIT 8
#define MIN(a,b) (a<b? a:b)
#define MAX(a,b) (a>b? a:b)
#define ROW 9
#define COL 10

#define END_VERTEX_X 3
#define END_VERTEX_Y 4

char mat[ROW][COL]  = {{1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
                       {1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
                       {1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
                       {0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
                       {1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
                       {1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
                       {1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
                       {1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
                       {1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }};

static char visited[ROW][COL];



void dfs_modified(char mat[][COL], char x, char y, char metric)
{
	int  i = 0;
	int  j = 0;
	int startX = 0;
	int startY = 0;
    printf("(%d, %d)\r\n",x,y);
	
	if((x == END_VERTEX_X) && ( y == END_VERTEX_Y))
	{
		visited[x][y] = MIN(visited[x][y], metric+1);
		printf("Reached target !\r\n");
		return;
	}
	else
		visited[x][y] += 1+metric;

	startX = x-1;
	startY = y-1;
	
	if(x<1)
	{
		startX = 0;		
	}
	if(y<1)
	{
		startY = 0;
	}
	// Loop..
	for(i=startX; i<x+2; i++)
	{
		for(j=startY; j<y+2; j++)
		{
			if((visited[i][j]==0) && (mat[i][j] == 1))
			{				
				dfs_modified(mat, i, j, visited[x][y]);
			}
		}
	}
}	

int main()
{
	int i = 0;
	int j = 0;
	
	for(i=0; i< ROW; i++)
	{
		for(j=0; j<COL; j++)
		{
			visited[i][j] = 0;
		}
	}
	

	dfs_modified(mat,0,0,visited[0][0]);
	printf("Shortest route in binary maze is %d\r\n", visited[END_VERTEX_X][END_VERTEX_Y]);
	
	for(i=0; i< ROW; i++)
	{
		for(j=0; j<COL; j++)
		{
			printf("%d ",visited[i][j]);
		}
		printf("\r\n");
	}
	return 0;
}