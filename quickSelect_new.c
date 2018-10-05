#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *a, char *b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

char partition(char arr[], char left, char right);

char quickSelect(char arr[], char left, char right, char n)
{
	if(left < right)
	{
		char pivot = partition(arr, left, right);
		
		if( n < pivot )
		{
			printf("left\r\n");
			quickSelect(arr, left, pivot - 1,n);
		}
        else if ( n > pivot )
		{
			printf("right\r\n");
			quickSelect(arr, pivot + 1, right, n);
		}
		else
			return arr[pivot];
	}
	else
		return arr[left];
}

char partition(char arr[], char left, char right)
{
	char pivot = arr[left];
	char pivotIdx = left;
	char leftEnd = left;
	char rightEnd = right;
	char numElem = right - left + 1;
	left+=1;
	while(left < right)
    {
		printf("l = %d, r = %d\r\n", left, right);
    	while(pivot > arr[left] && left < rightEnd)
	    {
			left++;
	    } 		
		
    	while(pivot < arr[right] && right > leftEnd)
	    {
			right--;
	    } 		

		if(left < right)
		{
			swap(&arr[left],&arr[right]);
		}
	}
	
	swap(&arr[left-1], &arr[pivotIdx]);
	return (left-1);
}

int main()
{
	char array[] = {11,9,4,1,13,7}; //1 4 7 9 11
	
	printf("The 2nd largest element is %d\r\n", quickSelect(array,0,6,2));
	printf("The 3rd largest element is %d\r\n", quickSelect(array,0,6,3));
	printf("The 4th largest element is %d\r\n", quickSelect(array,0,6,4));
	
	return 0;
}