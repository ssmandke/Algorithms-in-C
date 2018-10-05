
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include<string.h>

#define bool char
#define true 1
#define false 0
#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int *arr, int l, int r)
{
    int pivot = arr[l];
    int left = l+1;
    int right = r;
    int rightEnd = 0;
    int leftEnd = r+1;
    
    while(left < right)
    {
        while(arr[left] < pivot && left < leftEnd) 
            left++;
        while(arr[right] > pivot && right > rightEnd)
            right--;
        if(left < right)
            swap(&arr[left], &arr[right]);
        
    }
    
    swap(&arr[l], &arr[left-1]);
    
    return (left -1);
    
    
}

void quickSort(int *nums, int left, int right, int k)
{
    if(left < right)
    {
        int pivot = partition(nums, left, right);

        if(pivot == -1)
            return;
        quickSort(nums, left, pivot, k);
        quickSort(nums, pivot+1, right,k);
        
    }
    
    //return -1;
}

int findKthLargest(int* nums, int numsSize, int k) {
    
    if(numsSize == 2)
    {
        if(k==1)
        {
          return nums[0]>nums[1]?nums[0]:nums[1];   
        }
        
        return nums[0]>nums[1]?nums[1]:nums[0];
    }   
    
    if(numsSize == 3)
    {
        for(int i = 0; i < 2; i++)
        {
            for(int j = i+1; j < 3; j++)
            {
              if(nums[i] > nums[j] )
              {
                swap(&nums[i], &nums[j]);                  
              }                
            }
        }
   
       return nums[numsSize-k];
    }
    
    quickSort(nums, 0, numsSize-1,k);
    
    int i = 0;
    int m = 0;
    for(i=0; i<numsSize; i++)
    {
        if(i < numsSize && nums[i] != nums[i+1])
            m++;            
            
        printf(" %d ", nums[i]);
    }
    printf("\r\n");
    
    if(m == 0)
        return nums[numsSize-k];
    
    return nums[numsSize-k];
    
}

int main()
{
	int myArray[] = { 9, 4 , 5,  76, 31, 12};
	
	
	findKthLargest(myArray, 6, 3);
	return 0;
}