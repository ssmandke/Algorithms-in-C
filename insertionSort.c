#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

int main()
{
  int array[] = {5, 2, 4 ,6 ,1 ,3};
  int i =0;
  int j=0;
  int key = 0;
  int k = 0;
  
  for(k=0; k<(sizeof(array)/sizeof(int)); k++)
  {
	  printf(" %d ", array[k]);
  }
  printf("\r\nStart of insertion Sort\r\n");
  for (i = 1; i < (sizeof(array)/sizeof(int)); i++)
   {
       key = array[i];
       j = i-1;
 
       /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
       while (j >= 0 && array[j] > key)
       {
           array[j+1] = array[j];
           j = j-1;
       }
       array[j+1] = key; //The insertion sort inserts the current key in its appropriate position
	   for(k=0; k<(sizeof(array)/sizeof(int)); k++)
  {
	  printf(" %d ", array[k]);
  }
  printf("\r\n");
  
   }
  
  printf("\r\n");
  
  for(i=0; i<(sizeof(array)/sizeof(int)); i++)
  {
	  printf(" %d ", array[i]);
  }

  return 0;
}