// Program to count islands in boolean 2D matrix
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
 
#define ROW 4
#define COL 5
 
 /*[["1","1","0","0","0"],["1","1","0","0","0"],["0","0","1","0","0"],["0","0","0","1","1"]]*/
 
char matrix [ROW][COL]= \
{{1,1,0,0,0}, 
 {1,1,0,0,0},
 {0,0,1,0,0},
 {0,0,0,1,1}};

#define MAX(a,b) (a>b? a:b)

int maxRegion = 0;

int dfs(char grid[][COL], int row, int col, int maxRow, int maxCol)
{
    if(row>maxRow || row<0 || col<0 || col>maxCol)
        return 0;
    
    if(grid[row][col] == 0)
    {
        return 0;
    }
    
    grid[row][col] = 0;
    
    int size = 1;
    int i = 0;
    int j = 0;
    
    for(i=row-1; i<row + 2; i++)
    {
        for(j=col-1; j<col +2; j++)
        {
           if(i!=row || j!=col)
           {
               size+= dfs(grid, i, j, maxRow, maxCol);
               //printf("%d ",size);
           }                
        }
    }
    
    return size;
}


int numIslands(char grid[][COL], int gridRowSize, int gridColSize) {
    
    int i = 0;
    int j = 0;
    int count = 0;
    
    for(i=0; i<gridRowSize; i++)
    {
        for(j=0; j<gridColSize; j++)
        {
            if(grid[i][j] == 1)
            {
               printf("(%d, %d)\r\n ",i,j);
               int size = dfs(grid, i , j, gridRowSize, gridColSize);
               maxRegion = MAX(size, maxRegion);
               count++;
            }
        }
    }
	printf("count  = %d\r\n",count);
    return count;
}

int main()
{
	numIslands(matrix, ROW, COL);
	return 0;
}