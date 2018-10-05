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

void merge(int arr[], int leftIdx, int midIdx, int rightIdx)
{
	int left = leftIdx;
	int right = rightIdx;
	int left_end = midIdx - 1;
	int mid = midIdx;
	int right_end = right;
	int numElem = right - left + 1;
	int *temp = malloc(sizeof(int) * numElem);
	int idx = 0;
	int jdx = leftIdx;
	
	while((left <= left_end) && (mid <= right_end))
	{
		if(arr[left] <= arr[mid])
		{
			temp[idx] = arr[left];
			left++;
			idx++;
		}
		else
		{
			temp[idx] = arr[mid];
			mid++;
			idx++;
			
		}
	}
	
	while(left <= left_end)
	{
			temp[idx] = arr[left];
			left++;
			idx++;		
	}

	while(mid <= right_end)
	{
			temp[idx] = arr[mid];
			mid++;
			idx++;
			
	}
	
	for(idx = 0; idx < numElem; idx++)
	{
		//printf(" %d ",temp[idx]);
		arr[jdx] = temp[idx];
		jdx++;
	}
	//printf("\r\n--x---\r\n");
	
}

void mergeSort(int arr[], int left, int right)
{
	if(left < right)
	{
		int mid = (left + right)/2;
		mergeSort(arr,left, mid);
		mergeSort(arr,mid+1, right);
	    merge(arr,left, mid+1, right);
	}
}

int main()
{
  int array[] = {5, 2, 4 ,6 ,1 ,3};
  int i = 0;
  
  for (i=0; i < sizeof(array)/sizeof(int); i++)
  {
	  printf(" %d ", array[i]);
  }

  mergeSort(array, 0, 6);
  printf("\r\n");
  for (i=0; i < sizeof(array)/sizeof(int); i++)
  {
	  printf(" %d ", array[i]);
  }
  
  return 0;
}