
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int retVal[2] ={0,0};

int input[] = {2, 7, 11, 15};
/**
 * Note: The returned array must be malloced, assume caller calls free().
 
*/
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int *arr, int l, int r)
{
    int pivot = arr[l];
    int leftEnd = l;
    int rightEnd = r;
    int left = l+1;
    int right = r;
    
    while(left < right)
    {
        while(arr[left] < pivot && left <= rightEnd)
            left++;
        while(arr[right] > pivot && right >= leftEnd)
            right--;
        
        if(left < right)
        {
           swap(&arr[left], &arr[right]);    
        }                
    }
    
    swap(&arr[l], &arr[left-1]);
    return left - 1;
    
}
void quickSort(int nums[], int left, int right)
{
    if(left < right)
    {
        int pivot = partition(nums, left, right);
        quickSort(nums, left, pivot-1);
        quickSort(nums, pivot+1, right);
    }
}

int* twoSum(int nums[], int numsSize, int target) {
    
    
    int i = 0;
    int left = 0;
    int right = 0;
    int tmpSum = 0;
    
    quickSort(nums, 0, numsSize-1);
    left = 0;
    right = numsSize-1;
    
    for(i=0; i < numsSize; i++)
    {
        tmpSum = nums[left] + nums[right];
        
        if(tmpSum > target)
        {
            right--;            
        }
        else if(tmpSum < target)
        {
            left++;
        }
        else
        {
            retVal[0] = nums[left];
            retVal[1] = nums[right];
			printf("found1!");
            break;
        }
        
    }       
	
    return &retVal[0];    
}

int main()
{
	int i = 0;
	for(i=0; i<sizeof(input)/sizeof(int); i++)
	{
		printf("%d ", input[i]);
	}
	
	printf("\r\n");
	
	twoSum(input, sizeof(input)/sizeof(int), 9);
	
	for(i=0; i<sizeof(input)/sizeof(int); i++)
	{
		printf("%d ", input[i]);
	}
	
	printf("\r\n");
	
	return 0;
}