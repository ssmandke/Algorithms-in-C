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

#define INT_MIN    -1
#define INT_MAX     255
#define parent(x) (x/2)
#define left(x)  (2*x + 1)
#define right(x) (2*x + 2)

char array1[] = {12,3,4,15,10,8,6,7,0};
char array[] = {12,3,4,15,10,8,6,7};
char heapSize = sizeof(array)/sizeof(char);

void max_heapify(char arr[], char i);

char heap_extract_max(char arr[]);

void decrease_key(char arr[], char i, char new_val)
{
	arr[i] = new_val;
	
	while(i< heapSize && arr[i]> arr[parent(i)] && i > 0)
	{
		swap(&arr[i], &arr[parent(i)]);
		i = parent(i);
	}
}

void delete_key(char arr[], char i)
{
	arr[i] = arr[heapSize-1];
	heapSize = heapSize - 1;
	
	max_heapify(arr,0);
}

char heap_maximum(char arr[])
{
	return arr[0];
}

void heap_increase_key(char arr[], char i, char key)
{
	if(key < arr[i])
		printf("\r\nError\r\n");
	
	arr[i] = key;
	
	while((i>0) && (arr[i] > arr[parent(i)]))
	{
		swap(&arr[i], &arr[parent(i)]);
		i = parent(i);
	}
}

void max_heap_insert(char arr[], char key)
{
	heapSize+=1;
	arr[heapSize]= -254;
	heap_increase_key(arr, heapSize, key);
}

char heap_extract_max(char arr[])
{
	if(heapSize < 1)
		return -1;
	
	char max = arr[0];
	arr[0] = arr[heapSize-1];
	heapSize = heapSize - 1;
	
	max_heapify(arr,0);
	return max;
}

void max_heapify(char arr[], char i)
{
	char leftIdx = left(i);
	char rightIdx = right(i);
	char max = i;
	
	if((leftIdx < heapSize) && (arr[leftIdx] > arr[max]))
	{
		max = leftIdx;
	}
	if((rightIdx < heapSize) && (arr[rightIdx] > arr[max]))
	{
		max = rightIdx;
	}
	if(i!=max)
	{
		//printf("\r\n%d %d\r\n", arr[i], arr[max]);
		swap(&arr[i],&arr[max]);
	    max_heapify(arr, max);
	}	
}

void build_max_heap(char arr[])
{
	int i = heapSize/2; //To start at the leaf nodes, we divide by 2..
	
	for (; i>=0; i--)
	{
		max_heapify(arr,i);
	}
}

void heapSort(char arr[], char len)
{
	build_max_heap(arr);
	int i  = 0;
	int j  = 0;
	

	for (i=len-1; i>0; i--) //go from 1 to N..then from 1 to N-1 ...and so. on..
	{
		swap(&arr[0], &arr[i]); //Swap heap top with A[N] (in this case i because the loop is downcounting. Then max_Heapify the rest and repeat
		heapSize = heapSize - 1;

		max_heapify(arr, 0);
	}
}

int main()
{
  char i = 0;
  char counter = heapSize;
  printf("\r\ncounter = %d\r\n",counter);
  for(i=0; i<counter;i++)
  {
	  printf(" %d ",array[i]);
  }

  heapSort(array, heapSize);
  
  printf("\r\n");
  
  for(i=0; i<counter;i++)
  {
	  printf(" %d ",array[i]);
  }
  
  //Reset the sorted array to initial values etc.
  //{12,3,4,15,10,8,6,7};
  //for(i=0; i<counter;i++)
  {
	array[0] = 12;
    array[1] = 3;
	array[2] = 4;
	array[3] = 15;
	array[4] = 10;
	array[5] = 8;
	array[6] = 6;
	array[7] = 7;
  }  
  heapSize = sizeof(array)/sizeof(char);
  printf("\r\nReset the array\r\n");
  for(i=0; i<counter;i++)
  {
	  printf(" %d ",array[i]);
  }
  
  printf("\r\nAgain..build the max heap\r\n");
  build_max_heap(array);
  printf("\r\n heap extract max = %d\r\n",heap_extract_max(array));
  
  for(i=0; i<counter-1;i++)
  {
	  printf(" %d ",array[i]);
  }
  printf("\r\n");
  
  printf("\r\n heap increase key from %d to %d \r\n", array[2], 41);
  heap_increase_key(array, 2, 41);
  for(i=0; i<counter-1;i++)
  {
	  printf(" %d ",array[i]);
  }
  printf("\r\n\r\ndelete_key %d\r\n", array[3]);
  delete_key(array, 3);
    
  for(i=0; i<heapSize;i++)
  {
	  printf(" %d ",array[i]);
  }
  
  printf("\r\n\r\n");
  return 0;
}
