#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define bool char

#define MAX(a,b) (a>b?a:b)
#define true 1
#define false 0

int maxWeight = 5;

#define N_VAL_CNT 5
#define MAX_WT_CNT 6

unsigned int val[] = {100,20,60,40}; 
unsigned int wt[] = {3,2,4,1}; 
unsigned int W = 5 ;


int main()
{

	unsigned int dp[4+1][5+1];
	unsigned int i , j;
	unsigned int x = 12;
	int y = 12;
	
	for(i=0; i < 5; i++) //values
	{
		for(j=0; j < 6; j++) //weights upto 5;;
		{
			dp[i][j] = 0;
		}
	}
	
	for(i=0; i < 5; i++) //values
	{
		for(j=0; j < 6; j++) //weights upto 5;;
		{
			printf(" %d ", dp[i][j]);	
	    }
		printf("\n");
	}
	printf("\n");
	printf("\n");
	for(i=0; i < 5; i++) //values
	{
		for(j=0; j < 6; j++) //weights upto 5;;
		{
			if(i==0 || j==0)
			{
			    dp[i][j] =0 ;
			}
			else if(j>=wt[i-1])				
			{
				dp[i][j] = MAX(dp[i-1][j], dp[i-1][j-wt[i-1]] + val[i-1]);
							
				if(dp[i][j] < 0)
			    {
				   printf(" %d %d %d %d\n",i,j, wt[i-1], val[i-1]);
				   printf(" %d %d %d %d\n", (i-1), (j-wt[i-1]), dp[i-1][j-wt[i-1]]);
			    }
			}
			else
			{
				dp[i][j] = dp[i-1][j];
			}
			
		}
	}
	for(i=0; i < 5; i++) //values
	{
		for(j=0; j < 6; j++) //weights upto 5;;
		{
			printf(" %d ", dp[i][j]);	
	    }
		printf("\n");
	}

	printf("\n\n\n%d, %d ,%d, %d \n\n",x, ~x, y , ~y);
	return 0;
}