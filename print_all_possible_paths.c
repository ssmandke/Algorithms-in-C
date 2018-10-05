#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//print all possible paths in a matrix....only move right or down..
#define ROW_COUNT 2
#define COL_COUNT 3

char matrix [ROW_COUNT][COL_COUNT] = {{ 1, 2, 3},
	                                  { 4, 5, 6}};

static char visited[ROW_COUNT][COL_COUNT];
static char path[50];
static char pathIndex = 0;


char isValid(char rowParent, char colParent, char idx, char jdx)
{
	int row[] = {1, 0};
	int col[] = {0, 1};
	int i = 0;
	
	for(i=0; i<2; i++)
	{
		
		if((rowParent + row[i] == idx) && (colParent + col[i] == jdx))
		{
			printf("--> %d, %d\r\n",rowParent + row[i],colParent + col[i]);
			return 1;
		}
	}
	
	return -1;	
}

void dfs(char matrix[][COL_COUNT], char row, char col)
{
	int i = 0;
	int j = 0;
	visited[row][col] = 1;
	path[pathIndex] = matrix[row][col];
	pathIndex++;
	printf("dfs(%d, %d)\r\n", row, col);
	if((row== ROW_COUNT-1) && (col == COL_COUNT-1))
	{
		while(i < pathIndex)
		{
			printf(" %d, ",path[i]);
			i++;
		}
		//printf(" %d\r\n", matrix[ROW_COUNT-1][COL_COUNT-1]);
	}
	
	for(i = 0; i<ROW_COUNT; i++)
	{
		for(j = 0; j<COL_COUNT; j++)
		{
			if((visited[i][j]==0) && (isValid(row,col,i,j) == 1))
			{
				dfs(matrix, i, j);
			}
		}
	}
	
	visited[row][col] = 0;
	pathIndex--;
}
					
int main()
{
  int i = 0;
  int j = 0;
  
  	
  for(i = 0; i<ROW_COUNT; i++)
  {	
	for(j = 0; j<COL_COUNT; j++)
	{
		printf(" %d ",matrix[i][j]);
	}
	printf("\r\n");
  }
  dfs(matrix,0,0);
  return 0;
}