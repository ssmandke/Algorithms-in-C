#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *a, char *b)
{
   char temp = *a;
   *a = *b;
   *b = temp;
}

void reverseArray(char arr[], char len, char start)
{
	int i = 0;
	
	for(i=start; i < len/2; i++)
	{
		swap(&arr[i], &arr[len-i-1]);
	}
}

void rotateArrayInPlace(char arr[], int len, int places)
{
	char start = 0;
	reverseArray(arr, len-places, start);
	reverseArray(arr, places, start + len - places);
	reverseArray(arr, len, start);
}

int main(void) 
{
   char arr[] ={1,2,3,4,5,6,7};   //gives 5 1 2 3 4
   char N = sizeof(arr)/sizeof(char);
   int i = 0;
   int j = 0;
   int prevtemp = arr[0];
   int temp  = prevtemp;
   
   for(j=0; j<N; j++)
   {
	   printf(" %d ",arr[j]);
   }

   printf("\r\n--->\r\n");

   rotateArrayInPlace(arr, 7, 2);

   for(i=0; i<N; i++)
   {
	   printf(" %d ",arr[i]);
   }
   printf("\r\n");
   
   
   return 0;
}