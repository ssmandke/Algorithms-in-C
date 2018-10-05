#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>

#define NUM_CNT 40

int median[NUM_CNT];
int array[NUM_CNT];
int array_copy[NUM_CNT];

#define IS_ODD(x) (x & 0x01)

unsigned long modSum = 0;

void min_heapify(int array[], int idx)
{
	int left = (2 * idx) + 1;
	int right = (2 * idx) + 2;
	int minNode = idx;
	
	if((left > 10000) || (right > 10000))
		return;
	
    printf("idx = %d, Left = %d, Right = %d\r\n",idx, array[left],array[right]);
	if((array[minNode] < array[left]) && (left < heapSize))
	{
		minNode = left;
	}
	
	if((array[minNode] < array[right]) && (right < heapSize))
	{
		minNode = right;
	}
	
	if(idx !=minNode)
	{
	    swap(&array[idx], &array[minNode]);
	    //printf("Swap %d, %d\r\n\r\n", array[idx],array[minNode]);
		min_heapify(array, minNode);
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
    int indexOfKey = 0;
	
    if((fp = fopen("C:\\Users\\smandke\\Documents\\median1.txt", "r+")) == NULL) {
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
		array_copy[idx] = v1;
		//printf("%d, ",array[idx]);
		idx++;		
	}

	printf("\r\n now to sorted array\r\n");
	
	// Insertion sort...
	for(idx = 1; idx < NUM_CNT; idx++)
	{
		key = array[idx];
	    jdx = idx;

        while((jdx > 0) && (array[jdx - 1] > key))
		{
			array[jdx] = array[jdx - 1];
			jdx--;
		}
		
		array[jdx] = key;
	}
	
	// Median
	for(idx = 0; idx < NUM_CNT; idx++)
	{
		int tmp = array_copy[idx];

		if(IS_ODD(tmp))
	    {
			tmp = (tmp - 1)/2;
			median[idx] = array[tmp];
			//printf("Odd [%d] = %d, median = %d\r\n",(idx + 1),array[idx], median[idx]);			
		}
		else
		{
			tmp = (tmp)/2;
			median[idx] = array[tmp];
            //printf("Even[%d] = %d, median = %d\r\n",(idx + 1),array[idx], median[idx]);			
		}

		modSum+=median[idx];
	}
	
	//modSum = modSum%10000;
	printf("\r\nModSum modulo 10000 = %d\r\n", modSum);
	return 0;	
}