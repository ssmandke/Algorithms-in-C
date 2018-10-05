#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include<string.h>

#define true 1
#define false 0
#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)

#define NUM_ELEM 8 
             //0  1  2   3   4   5  6  7
int array[] = {7, 8, 17, 19, 21, 1, 2 ,3};

void printArray()
{
	int i = 0;
	for(i =0; i< NUM_ELEM; i++)
	{
		printf(" %d ", array[i]);
	}
	
	printf("\r\n");
}

void merge(int *arr, int left, int mid, int right)
{
    int numElem = right - left + 1;
    int i = left;
    int j = mid;
    int *mallocArr = malloc(sizeof(int) * numElem);
    int k = 0;
    printf("left, mid, right = %d %d %d\r\n ", arr[left], arr[mid], arr[right]);
    while((i<mid) && (j <= right))
    {
        if(arr[i] < arr[j])
        {
           mallocArr[k] = arr[i]; 
           i++;
        }
        else
        {
           mallocArr[k] = arr[j];
           j++;            
        }
        printf("%d ", mallocArr[k]);
        k++;
    }
          
    while(i<mid)
    {
        mallocArr[k] = arr[i];
        k++;
        i++;
    }
          
    while(j<=right)
    {
        mallocArr[k] = arr[j];
        k++;
        j++;
    }
          printf("\r\nAfter merge\r\n");
		  k = left;
    for(i=0; i<numElem; i++)
    {
        arr[k] = mallocArr[i];
		k++;
        printf("%d ", arr[i]);
    }
    
    printf("\r\n");
          
}

void mergeSort(int *nums, int left, int right)
{    
    if(left < right)
    {
        int mid = (left + right)/2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid+1, right);
        merge(nums, left, mid+1, right);
    }
}

int main()
{
   printArray();
	
   printf("\r\n");
   
   mergeSort(array,0,NUM_ELEM-1);
   
   printArray();
	
   printf("\r\n");

   return 0;
}