#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define bool char
#define true 1
#define false 0

#define MIN(a,b) (a<b?a:b)
#define MAX(a,b) (a>b?a:b)
 
int arr1[] = {1, 2 ,15 , 18, 21, 23, 33, 34}; // log(8) = 3
int arr2[] = {3, 4 ,8, 19}; //log(4) = 2 

//log(8+4) = log(12) = 3.5?

int median(int arr1[], int len1, int arr2[], int len2)
{
  int retVal = -1;
  int numTotal = len1+len2;
  int medianIdx1 = -1;
  int medianIdx2 = -1;
  int i = 0;
  int j = 0;
  int count = 0;
  int median1, median2;

  if(numTotal & 0x01)
  {
      medianIdx1 = medianIdx2  = numTotal/2;
  }
  else
  { 
     medianIdx1 = numTotal/2;
     medianIdx2 = medianIdx1-1;
  }

  while((i < len1) && (j< len2))
  {
    if(arr1[i] < arr2[j])
    {
      if(count == medianIdx1)
      {
        median1 = arr1[i];
      }
      else if(count == medianIdx2)
      {
        median2 = arr1[i];
      }

      i++; 
    }
    else
    { 
      if(count == medianIdx1)
      {
        median1 = arr2[j];
      }
      else if(count == medianIdx2)
      {
        median2 = arr2[j];
      }

       j++;
    }
   
    count++;
  }
  
  if((medianIdx1 == -1) || (median2 == -1))
  {
     while(i < len1)
     {
      if(count == medianIdx1)
      {
        median1 = arr1[i];
      }
      else if(count == medianIdx2)
      {
        median2 = arr1[i];
      }
      i++; count++;
     }

     while(j < len2)
     {
      if(count == medianIdx1)
      {
        median1 = arr2[j];
      }
      else if(count == medianIdx2)
      {
        median2 = arr2[j];
      }
      j++; count++;
     }
  }
  
  retVal = median1 + median2;
  printf("\r\nMedian 1 = %d, Median 2 = %d\r\n", median1, median2);
  retVal = retVal / 2;

  return retVal;
}

int main()
{
  printf("Median of 2 sorted arrays = %d\r\n", median(arr1, sizeof(arr1)/sizeof(int), arr2, sizeof(arr2)/sizeof(int)));
  return 0;
}