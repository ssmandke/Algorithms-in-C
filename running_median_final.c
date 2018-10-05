#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>

#define NUM_CNT 10000
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
	int maxNode = idx;
	
	if((left > maxHeapSize) || (right > maxHeapSize))
		return;
	
    //printf("idx = %d, Left = %d, Right = %d\r\n",idx, array[left],array[right]);
	if((array[maxNode] < array[left]) && (left < maxHeapSize))
	{
		maxNode = left;
	}
	
	if((array[maxNode] < array[right]) && (right < maxHeapSize))
	{
		maxNode = right;
	}
	
	if(idx !=maxNode)
	{
	    swap(&array[idx], &array[maxNode]);
		max_heapify(array, maxNode);
	}
}


void min_heapify(int array[], int idx)
{
	int left = (2 * idx) + 1;
	int right = (2 * idx) + 2;
	int minNode = idx;
	
	if((left > minHeapSize) || (right > minHeapSize))
		return;
	
    //printf("idx = %d, Left = %d, Right = %d\r\n",idx, array[left],array[right]);
	if((array[minNode] > array[left]) && (left < minHeapSize))
	{
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
	
    if((fp = fopen("C:\\Users\\smandke\\Documents\\median.txt", "r+")) == NULL) {
        printf("No such file\n");
        return 1;
    }
    
	while (true) 
	{
        int ret = fscanf(fp, "%u", &v1);
		
		if(ret == EOF) 
		{
            break;
		}
		
		array[idx] = v1;
		idx++;		
		
		if(idx==NUM_CNT)
			break;
	}

	// Median
	for(idx = 0; idx < NUM_CNT; idx++)
	{
		int tmp = array[idx];
		
		//printf("\r\ntop max = %d, min = %d", maxHeapArray[0], minHeapArray[0]);
		//printf(" size max = %d, min = %d ", maxHeapSize, minHeapSize);
		if(currentMedian > tmp)
		{
			//insert in max heap
			maxHeapArray[maxHeapSize] = tmp;
			maxHeapSize++;

			//printf("put %d in maxheap ", tmp);
			if(maxHeapArray[maxHeapSize - 1] > maxHeapArray[0])
			{
				swap(&maxHeapArray[maxHeapSize - 1], &maxHeapArray[0]);
			}
		}
		else
		{
			//insert in min heap
			minHeapArray[minHeapSize] = tmp;
			minHeapSize++;
            //printf("put %d in minheap ", tmp);
			if(maxHeapArray[minHeapSize - 1] > minHeapArray[0])
			{
				swap(&minHeapArray[minHeapSize - 1], &minHeapArray[0]);			
			}
			//printf("minHeapArray[] = %d\r\n", minHeapArray[minHeapSize - 1]);
		}
#if 1		
		if(((maxHeapSize > minHeapSize)  && ((maxHeapSize-minHeapSize) > 1))  ||
			(maxHeapSize < minHeapSize)  && ((minHeapSize-maxHeapSize) > 1))
		{
			//printf("swap of max = %d, min = %d\r\n", maxHeapArray[0], minHeapArray[0]);
			if (maxHeapSize > minHeapSize) {
                    swap(&maxHeapArray[maxHeapSize - 1], &maxHeapArray[0]);
                    minHeapArray[minHeapSize++] = maxHeapArray[--maxHeapSize];
                    swap(&minHeapArray[minHeapSize - 1], &minHeapArray[0]);	
                    //build_max_heap(maxHeapArray, maxHeapSize);
					//build_min_heap(minHeapArray, minHeapSize);
                } else {
                    swap(&minHeapArray[minHeapSize - 1], &minHeapArray[0]);	
                    maxHeapArray[maxHeapSize++] = minHeapArray[--minHeapSize];
                    swap(&maxHeapArray[maxHeapSize - 1], &maxHeapArray[0]);
                    //build_min_heap(minHeapArray, minHeapSize);
                    //build_max_heap(maxHeapArray, maxHeapSize);
                }
		}
#endif
        build_min_heap(minHeapArray, minHeapSize);
        build_max_heap(maxHeapArray, maxHeapSize);
#if 1		
		if(maxHeapSize == minHeapSize)
		{
			currentMedian = maxHeapArray[0];
			//printf(" maxHeapTop1");
		}	
		else
		{
			if (maxHeapSize > minHeapSize) {
                currentMedian = maxHeapArray[0];
				//printf(" maxHeapTop2");
            } else {
                currentMedian = minHeapArray[0];
				//printf(" minheapTop");
            }
		}
#endif	
		if(idx > 1)
		{
			modSum+=currentMedian;
		}
		else
			modSum = array[0] + array[1];
		
		//printf(" median = %d, sum = %d\r\n", currentMedian, modSum);

	}
	
	modSum = modSum%10000;
	printf("\r\nModSum modulo 10000 = %d\r\n", modSum);
	return 0;	
}
