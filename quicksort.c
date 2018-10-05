#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

int partition(int arr[], int leftIdx, int right)
{
	int pivot = arr[leftIdx];
	int left = leftIdx + 1;
	int left_end = left;
	int right_end = right;
	int numElem = right - left + 1;
	
	while(left <= right)
	{
    	while((pivot >= arr[left]) && (left <= right_end))
	    {
		  left++;
	    }
    	while((pivot < arr[right]) && (right >= left_end))
	    {
		  right--;
	    }

		if(left < right)
		{
			printf("\r\n Swap L= %d , R = %d\r\n",arr[left],arr[right]);
			swap(&arr[left], &arr[right]);
		}
		
	}
	
	swap(&arr[left -1],&arr[leftIdx]);
	printf("retVal = %d\r\n", (left-1));
	return (left - 1);
}

void quickSort(int arr[], int left, int right)
{
  if(left < right)
  {
	  int pivot = partition(arr, left, right);
	  quickSort(arr, left, pivot -1 );
	  quickSort(arr, pivot +1, right);
  }	  
}

int main()
{
  int array[] = {5, 2, 4 ,6 ,1 ,3};
  int left = 0;
  int i = 0;
  int right = sizeof(array)/sizeof(int);

  while(i< right)
  {
	  printf(" %d ",array[i]);
	  i++;
  }
  
  quickSort(array,left, right);
  i=0;
  while(i< right)
  {
	  printf(" %d ",array[i]);
	  i++;
  }
  
  printf("\r\n");
  return 0;
}