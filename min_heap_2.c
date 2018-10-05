#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>

int  heapSize=40;

typedef struct node
{
  int v; // node number
  struct node *left;
  struct node *right;
}node_t;

void swap (int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int heap_arr[6];

void min_heapify(int array[], int idx)
{
	unsigned int left = (2 * idx) + 1;
	unsigned int right = (2 * idx) + 2;
	unsigned int minNode = idx;
	
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
		printf("Swap %d, %d\r\n\r\n", array[idx],array[minNode]);
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

void heapsort(int arr[], int length)
{
	int i = 0;
     
	build_min_heap(arr, length);
	
	for(i=length-1; i > 0; i--)
	{
		swap(&arr[0], &arr[i]);
		heapSize = heapSize - 1;
		min_heapify(arr,0);
	}
}

int main()
{
	FILE *fp;
    int v1;
	int idx = 0;
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
		
		heap_arr[idx] = v1;
		//printf("heap[%d] = %d\r\n", idx, heap_arr[idx]);
		idx++;		
	}

	//build_min_heap(heap_arr,heapSize);
	//min_heapify(heap_arr,0);
	idx = 0;
	heapsort(heap_arr,heapSize);

	while(idx < 40)
	{
		printf("%d, ",heap_arr[idx]);
        idx++;		
	}
	return 0;
}