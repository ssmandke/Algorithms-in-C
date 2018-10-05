#include <stdio.h>

//Dutch Flag Problem
int arr[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};

void swap(int *a, int *b)
{
   int temp = *a;
   *a = *b;
   *b = temp;
}

void printArray()
{
	int i = 0;
	for (i=0; i< sizeof(arr)/sizeof(int) ;i++)
	{
		printf(" %d ",arr[i]);
	}
	printf("\r\n");
}
void sort012(int a[], int arr_size)
{
    int lo = 0;
    int hi = arr_size - 1;
    int mid = 0;
 
    while (mid <= hi)
    {
        switch (a[mid])
        {
        case 0:
            swap(&a[lo++], &a[mid++]);
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(&a[mid], &a[hi--]);
            break;
        }
    }
}

int main(void) 
{
	// your code goes here
	int left = 0;
	int right = sizeof(arr)/sizeof(int) - 1;
	int mid = (left+right)/2;
	int len = right - left + 1;
	int count = 0;
	printf("l = %d r = %d\r\n", left, right);
	int  i = 0;
	printArray();
	
	sort012(arr,len);
	printf("l = %d r = %d\r\n", left, right);
	
	printArray();
	return 0;
}

