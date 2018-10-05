#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include<string.h>

#define true 1
#define false 0
#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)


long longestPathLen = 0;
long currPathLen = 1;

int mymatrix[3][3] ={ {9, 9, 4},{6 ,6 ,8}, {2, 1, 1}};

int rr[] = {1 ,-1 , 0 ,0};
int cc[] = {0,  0,  1, -1};

char checkValid(int row, int col,  int matrixRowSize, int matrixColSize)
{
    if(row>=0 && row<matrixRowSize)
    {
        if(col>=0 && col<matrixColSize)
        {
            return 1;
        }
    }
    
    return 0;
}

void dfs(int matrix[][3], int matrixRowSize, int matrixColSize, int row, int col)
{
    int i, j;
    int k = 0;
            int found = 0;
            printf("row = %d, col = %d val = %d\r\n", row,col, matrix[row][col]);
            for(k= 0; k <4 ;k++)
            {
                int r = row + rr[k];
                int c = col + cc[k];                

                if(checkValid(r,c,matrixRowSize,matrixColSize) == 1)
                {
                    if(matrix[row][col] < matrix[r][c])
                    {
						printf("matrix[%d][%d] = %d\r\n",r,c, matrix[r][c]);
                    
                        found = 1;
                        currPathLen++;
                        dfs(matrix,matrixRowSize,matrixColSize, r, c);                         
                    }                    
                }
            }
            
            if(found == 0)
            {
				printf("Done - currPathLen = %d\r\n\r\n",currPathLen);
                longestPathLen = MAX(longestPathLen, currPathLen);
				currPathLen = 1;
            }            
   
}

int longestIncreasingPath(int matrix[][3], int matrixRowSize, int matrixColSize) {
    int i = 0;
    int j = 0;
    
    for(i=0; i<matrixRowSize; i++)
    {
        for(j=0; j<matrixColSize; j++)
        {
            printf("%d, ",matrix[i][j]);
        }
        printf("\r\n");
    }

    for(i=0; i<matrixRowSize; i++)
    {
        for(j=0; j<matrixColSize; j++)
        {
            dfs(matrix, matrixRowSize, matrixColSize, i,j);
        }
    }
            
    
    return longestPathLen;
}

int main()
{
  longestIncreasingPath(mymatrix, 3,3);
  printf("longest path length = %d\r\n",longestPathLen);
  return 0;
}