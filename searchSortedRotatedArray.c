
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a,b) (a<b? a:b)
#define MAX(a,b) (a>b? a:b)

char sortedArr[] = {3,4,5,8,7,8,9,10,1,2};

int main()
{
  int left = 0;
  int right = sizeof(sortedArr);
  int key = 5;
  
  while(left!=right)
  {
	  if(arr[left] < arr[right])
	  {
		  int mid = (arr[left] + arr[right])/2;
		  
		  if(arr[mid] > key)
		  {
			  right = mid-1;
		  }
		  else
			  left = mid+1;
	  }
  }
  
  return 0;
}
