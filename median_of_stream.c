#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>

#define NUM_CNT 10000

int median[NUM_CNT];
int array[NUM_CNT];
int array_copy[NUM_CNT];

#define IS_ODD(x) (x & 0x01)

unsigned long modSum = 0;

int main()
{
	FILE *fp;
    int v1;
	int idx = 0;
	int jdx = 0;
	int key = 0;
    int indexOfKey = 0;
	
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