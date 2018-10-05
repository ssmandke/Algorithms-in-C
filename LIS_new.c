
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


int array[] = {101 ,99, 12, 71, 13, 6, 14, };

void printLIS(int lis[], int lisIndex, int arr[], int max); //prints in LIS order..

void printLIS(int lis[], int lisIndex, int arr[], int max) 
{
    if(max == 0) {
        return;
    }
    if(lis[lisIndex] == max) {
        printLIS(lis,lisIndex-1, arr, max-1);
        printf(" %d ", arr[lisIndex]);
    } else {
        printLIS(lis,lisIndex-1, arr, max);
    }

}

void LIS_func(int arr[], int len)
{
	int i = 0;
	int j = 0;
	int *LIS = malloc(sizeof(int) * len);
	int maxLen = 1;
	int lisIndex = -1;

	for(i= 0; i < len; i++)
	{
		LIS[i] = 1;
	}
	for(i=0 ; i<len; i++)
	{
		for(j=0; j<i; j++)
		{
			if((arr[j] < arr[i]) && (LIS[i] < LIS[j]+1))
			{
				LIS[i] = LIS[j] + 1;
				printf("%d %d\r\n", arr[i], arr[j]);
				if(maxLen < LIS[i])
				{
					maxLen = LIS[i];
                    lisIndex = i;					
				}
			}
		}
	}
	printf("\r\nmaxLen = %d\r\n", maxLen);
					
	for(i= 0; i < len ; i++)
	{
		printf(" %d ", LIS[i]);		
		
	}
	printf("\r\n");
	
	printLIS(LIS, lisIndex, arr, maxLen);
	
	for(i= len-1; i > 0 ; i--)
	{
	printf("\r\nLIS[%d] = %d ,maxLen = %d\r\n", i,LIS[i],maxLen);
					
		if(LIS[i] == maxLen)
		{
			printf("%d , ", arr[i]);
		    maxLen--;
		}
	}
	
	//
}

int main()
{
	LIS_func(array, sizeof(array)/sizeof(int));
	return 0;
}

