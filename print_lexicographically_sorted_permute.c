#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include<string.h>

#define true 1
#define false 0
#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)

void swap(char *x, char *y)
{
  char temp = *x;
  //printf("%c, %c are being swapped\r\n",*x, *y);
  *x = *y;
  *y = temp;
}

void insertionSort(char *arr, char arrLen)
{
	char key ,i, j;
	
	for(i=1; i < arrLen; i++)
	{
		key = arr[i];
		j = i-1;
		
		//printf("%c, %c\r\n", arr[i], arr[j]);
		
		while( j >= 0 && key < arr[j] )
		{
			//printf("shift\r\n");
			arr[j+1] = arr[j];
			
			j=j-1;
		}
		
		arr[j+1] = key;		
	}
}

void reverse(char *arr, char left, char right)
{
	char i = left;
	char j = right;
	char count = j - i + 1;
	count = count/2;
    //printf("reverse at left = %d, right = %d\r\n", left, right);
	
	while(count)
	{
		char temp = arr[i];
		arr[i] = arr[j];
		arr[j]= temp;
		count--;
	}
}

void lexico_permute(char *arr, char arrlen)
{
   int i = 0;
   int k = 0;
   int l = 0;
   
   int count = 1;
   int tmp = arrlen;
   
   while(tmp)
   {
	   count*=tmp--;	   
   }

   printf("permutation count = %d, for %d chars\r\n\r\n", count, arrlen);
   insertionSort(arr, arrlen);
   // printf("permute %s\r\n", arr);
   
   for(i=0; i< count; i++)
   {
	   int j = arrlen - 1;
	   l = -1;
	   k = -1;
	   
	   printf("%d) %s\r\n", i, arr);
	   
	   for(; j > 0; j--)
	   {
		   if(arr[j] > arr[j-1])
		   {
			   k = j - 1;
			   break;
		   }		   
	   }
	   if(k<0)
		   break;
	   for(j = 0; j < arrlen; j++)
	   {
		   if(arr[j] > arr[k])
		   {
			   l = MAX(l,j);
		   }
	   }
	 
       //printf("swap indices(k,l)= %d %d\r\n", k,l);	 
	   swap(&arr[l], &arr[k]);
	   reverse(arr, k+1, arrlen-1);
   }
}

int main()
{
   char string[] = "BACD";
   lexico_permute(string, strlen(string));
   return 0;
}