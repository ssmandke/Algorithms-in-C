#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

char numArray[] = { 1 , 2 ,3 ,4 ,5 ,6 ,7 ,8, 9 ,10};

void swap(char *a, char *b)
{
  char temp = *a;
  *a = *b;
  *b = temp;
}

void fisherYateShuffle(char arr[], char arrLen)
{
	int i = 0;
	srand(time(NULL));
	//Start from last element of array. Swap 1 by 1 with random element..
	//Random element is between 0 to ith value..
	//no need to run for first element ..
	//
	for(i = arrLen - 1; i > 0; i--)
	{
		int j = rand();
		
		j = j % (i+1); //N, N-1, N-2..are the divisors for the random pick..
		
		swap(&arr[i], &arr[j]);
	}
}

void printArray()
{
	int idx = 0;
	
	for(idx = 0; idx < sizeof(numArray); idx++)
	{
		printf(" %d ",numArray[idx]);
	}
   
   printf("\r\n");
}

int main()
{
	printArray();
	fisherYateShuffle(numArray, sizeof(numArray));
	printArray();
	return 0;
}
