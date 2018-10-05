
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX(a,b) (a>b? a:b)
#define MIN(a,b) (a<b? a:b)


int arr[] = {2, 3, 1 ,1 ,4};
int currPath = 0;
int minPath = 999;

int minPathCalc(int arr[], int len, int nextStop)
{
	int i = 0;
	
	if(nextStop == len - 1)
	{
		printf(" stop!\n");
		currPath++;
		return 0;
	}
	
	if(nextStop > len)
	{
		printf(" please stop!\n");
		return -1;
	}
	currPath++;
	printf("recur with nex stop %d\n", nextStop);
	for(i=arr[nextStop]; i > 0; i--)
	{
		printf(" %d ",i);
		if(minPathCalc(arr,len,i + nextStop) == 0)
		{
			minPath = MIN(minPath, currPath);
			printf("min path = %d\r\n", minPath);
			currPath = 1;
		}
	}

	return minPath;	
}
int main()
{
  minPathCalc(arr, sizeof(arr)/sizeof(int), 0);
  return 0;
}