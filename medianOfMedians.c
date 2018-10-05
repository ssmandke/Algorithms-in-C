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

/*
// It searches for x in arr[l..r], and partitions the array 
// around x.
int partition_new(char arr[], int l, int r, char x)
{
    // Search for x in arr[l..r] and move it to end
    int i;
    for (i=l; i<r; i++)
        if (arr[i] == x)
           break;
    swap(&arr[i], &arr[r]);
 
    // Standard partition algorithm
    i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}
 */
int partition(char arr[], int leftIdx, int right)
{
	int pivot = arr[leftIdx];
	int left = leftIdx + 1;
	int left_end = left;
	int right_end = right;
	int numElem = right - left + 1;
	//printf("\r\npartition : %d,%d ",leftIdx, right);
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
			///printf("\r\n Swap L= %d , R = %d\r\n",arr[left],arr[right]);
			swap(&arr[left], &arr[right]);
		}
		
	}
	
	swap(&arr[left -1],&arr[leftIdx]);
	//printf("retVal index = %d val = %d \r\n", (left-1), arr[left-1]);
	return (left - 1);
}

int partition_pivot(char arr[], int leftIdx, int right, char pivotIdx)
{
	int pivot = arr[pivotIdx];
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
			///printf("\r\n Swap L= %d , R = %d\r\n",arr[left],arr[right]);
			swap(&arr[left], &arr[right]);
		}
		
	}
	
	swap(&arr[left -1],&arr[pivotIdx]);
	//printf("retVal index = %d val = %d \r\n", (left-1), arr[left-1]);
	return (left - 1);
}

void quickSort(char arr[], int left, int right)
{
  if(left < right)
  {
	  int pivot = partition(arr, left, right);
	  quickSort(arr, left, pivot -1 );
	  quickSort(arr, pivot +1, right);
  }	  
}

char quickSelect(char arr[], int left, int right, int pivotIdx)
{
  if(left < right)
  {
	  int pivot = partition(arr, left, right);
	  
	  if(pivot == pivotIdx)
		  return arr[pivot];
	  
	  if(pivotIdx < pivot)
		  return quickSelect(arr, left, pivot -1 ,pivotIdx);
	  else
		  return quickSelect(arr, pivot +1, right,pivotIdx);
  }	  
}

char getMedian( char array[], char left, char right)
{
	char numElem = right - left + 1;
	printf("\r\n");
	if(numElem <= 5)
		quickSort(array,left,right);
	    char i = left;
		while(i <= right)
		{
			printf(" %d ", array[i]);
			i++;
		}
	    printf("median is %d\r\n", array[(left+right)/2]);
	    return array[(left + right)/2];
}
char select(char array[], char left, char right, char pivotIdx)
{
	char numElem = right-left+1;
	char i = 0;
	char j = 0;	
	printf("\r\nselect(array, %d, %d, %d)", left,right,pivotIdx);
	
    if((pivotIdx > 0) && ( pivotIdx <= right - left + 1))
	{
		numElem = (right - left + 1);
		char median[(numElem+4)/5];
		      
		for (i=0; i<numElem/5; i++)
		{
            median[i] = getMedian(array,left+i*5, left+i*5 + 4);
		}
        if (i*5 < numElem) //For last group with less than 5 elements
        {
            median[i] = getMedian(array,left+i*5, numElem%5); 
            i++;
        }    
#if 0
/* 		// Partition the > 5 set into subsets
		for (i=0; i< (numElem + 4)/5; i++)
		{
			char leftIdx = i*5;
			char rightIdx = leftIdx + 4;
			if(rightIdx > numElem)
				rightIdx = numElem - 1;
			median[i] = getMedian(array, leftIdx, rightIdx);

		} */
#endif
		printf("\r\nGetMedian() complete\r\n");

		// Find median of all medians using recursive call.
		// If median[] has only one element, then no need
		// of recursive call
		char medOfMed = (i == 1)? median[i-1]:
									 select(median, 0, i-1, i/2);
							 
		// Partition the array around a random element and
		// get position of pivot element in sorted array
		int pos = partition_pivot(array, left, right, medOfMed);
	 
		// If position is same as k
			if (pos-left == pivotIdx-1)
				return array[pos];
			if (pos-left > pivotIdx-1)  // If position is more, recur for left
				return select(array, left, pos-1, pivotIdx);
	 
			// Else recur for right subarray
			return select(array, pos+1, right, pivotIdx-pos+left-1);
	}
	
}

int main()
{
  char array[] = {12,15,16,17,18,13,14,6,7,8,1,2,3,4,5,9,10,11};
  char left = 0;
  char i = 0;
  char right = sizeof(array)/sizeof(char);
  
  //printf("\r\n3rd element is %d\r\n",quickSelect(array,0, right,3));
  //printf("\r\n4th element is %d\r\n",quickSelect(array,0, right,4));
  
  printf("\r\nMedian of medians is %d\r\n", array[select(array,0, right, 10)]);
  printf("\r\nMedian of medians is %d\r\n", array[select(array,0, right, 7)]);
  while(i<right)
  {
	  printf(" %d ",array[i]);
	  i++;
  }
  printf("\r\n");
  return 0;
}