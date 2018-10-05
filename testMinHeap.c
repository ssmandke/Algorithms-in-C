#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>

#define NUM_CNT 2
#define IS_ODD(x) (x & 0x01)

int array[NUM_CNT];
int minHeapArray[NUM_CNT];
int maxHeapArray[NUM_CNT];

unsigned long modSum = 0;
unsigned int minHeapSize = 0;
unsigned int maxHeapSize = 0;

void swap(int *a , int *b)
{
	int ptr = *a;
	*a = * b;
	*b = ptr;
}

void max_heapify(int array[], int idx)
{
	int left = (2 * idx) + 1;
	int right = (2 * idx) + 2;
	int minNode = idx;
	
	if((left > maxHeapSize) || (right > maxHeapSize))
		return;
	
    //printf("idx = %d, Left = %d, Right = %d\r\n",idx, array[left],array[right]);
	if((array[minNode] < array[left]) && (left < maxHeapSize))
	{
		minNode = left;
	}
	
	if((array[minNode] < array[right]) && (right < maxHeapSize))
	{
		minNode = right;
	}
	
	if(idx !=minNode)
	{
	    swap(&array[idx], &array[minNode]);
		max_heapify(array, minNode);
	}
}


void min_heapify(int array[], int idx)
{
	int left = (2 * idx) + 1;
	int right = (2 * idx) + 2;
	int minNode = idx;
	
	if((left > minHeapSize) || (right > minHeapSize))
		return;
	
    printf("idx = %d, Left = %d, Right = %d\r\n",idx, array[left],array[right]);
	if((array[minNode] > array[left]) && (left < minHeapSize))
	{
		printf("\r\nmin1 = %d",array[left]);
		minNode = left;
	}
	
	if((array[minNode] > array[right]) && (right < minHeapSize))
	{
		minNode = right;
	}
	
	if(idx !=minNode)
	{
	    swap(&array[idx], &array[minNode]);
		min_heapify(array, minNode);
	}
}

void build_max_heap(int array[], int length)
{
	int idx = 0;
	
	for(idx=(length/2); idx >=0; idx--)
	{
		max_heapify(array,idx);
	}
}

void build_min_heap(int array[], int length)
{
	int idx = 0;
	
	for(idx=(length/2); idx >=0; idx--)
	{
		min_heapify(array,idx);
	}
}


int main()
{
	FILE *fp;
    int v1;
	int idx = 0;
	int jdx = 0;
	int key = 0;
    int currentMedian = 0;
	minHeapArray[0] = 23;
	minHeapArray[1] = 35;
	minHeapSize = 2;
	build_min_heap(minHeapArray, minHeapSize);
	if(minHeapArray[0] !=23)
		printf("BAD!!\r\n");
	return 0;	
}
