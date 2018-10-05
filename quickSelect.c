#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *x, char *y)
{
  char temp = *x;
  *x = *y;
  *y = temp;
}

int partition(char arr[], int leftIdx, int right)
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
	printf("retVal index = %d val = %d \r\n", (left-1), arr[left-1]);
	return (left - 1);
}


char quickSelect(char arr[], int left, int right, int pivotIdx)
{
  if(left < right)
  {
	  int pivot = partition(arr, left, right);
	  
	  if(pivot == pivotIdx - 1)
		  return arr[pivot];
	  
	  if(pivotIdx < pivot)
		  return quickSelect(arr, left, pivot -1 ,pivotIdx);
	  else
		  return quickSelect(arr, pivot +1, right,pivotIdx);
  }	  
}

int main()
{
  char array[] = {5, 2, 4 ,6 ,1 ,3};
  char left = 0;
  char i = 0;
  char right = sizeof(array)/sizeof(char);
  
  printf("\r\n3rd element is %d\r\n",quickSelect(array,0, right,3));
  printf("\r\n4th element is %d\r\n",quickSelect(array,0, right,4));
  return 0;
}