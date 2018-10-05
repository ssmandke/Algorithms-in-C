#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a,b) (a>b? a: b)
#define MIN(a,b) (a<b? a: b)

/* Returns the product of max product subarray.  
   Assumes that the given array always has a subarray 
   with product more than 1 */
int maxSubarrayProduct(int arr[], int n) 
{ 
    // max positive product ending at the current position 
    int max_ending_here = 1; 
  
    // min negative product ending at the current position 
    int min_ending_here = 1; 
  
    // Initialize overall max product 
    int max_so_far = 1; 
  
    /* Traverse through the array. Following values are 
       maintained after the i'th iteration: 
       max_ending_here is always 1 or some positive product 
                       ending with arr[i] 
       min_ending_here is always 1 or some negative product  
                       ending with arr[i] */
    for (int i = 0; i < n; i++) 
    { 
        /* If this element is positive, update max_ending_here.  
           Update min_ending_here only if min_ending_here is  
           negative */
        if (arr[i] > 0) 
        { 
            max_ending_here = max_ending_here*arr[i]; 
            min_ending_here = MIN (min_ending_here * arr[i], 1); 
        } 
  
        /* If this element is 0, then the maximum product  
           cannot end here, make both max_ending_here and  
           min_ending_here 0 
           Assumption: Output is alway greater than or equal  
                       to 1. */
        else if (arr[i] == 0) 
        { 
            max_ending_here = 1; 
            min_ending_here = 1; 
        } 
  
        /* If element is negative. This is tricky 
           max_ending_here can either be 1 or positive.  
           min_ending_here can either be 1 or negative. 
           next min_ending_here will always be prev.  
           max_ending_here * arr[i] next max_ending_here 
           will be 1 if prev min_ending_here is 1, otherwise  
           next max_ending_here will be prev min_ending_here * 
           arr[i] */
        else
        { 
            int temp = max_ending_here; 
            max_ending_here = MAX(min_ending_here * arr[i], 1); 
            min_ending_here = temp * arr[i]; 
        } 
  
        // update max_so_far, if needed 
        if (max_so_far <  max_ending_here) 
          max_so_far  =  max_ending_here; 
    } 
  
    return max_so_far; 
} 
//char array[] =  {6, -3, -10, 0, 2};
int array[] = {-2, -3, 0, -2, -40};

/*void maxProductArray(char arr[], char len)
{
  int maxEndingSoFar = 1;
  int maxEndingHere = 1;

  int i = 0;
  
  for(i=0; i<len; i++)
  {
	  if(arr[i] !=0)
	  {
         maxEndingHere = maxEndingHere * arr[i];
	     maxEndingSoFar = MAX(maxEndingHere, maxEndingSoFar);
		 printf("maxhere = %d\r\n", maxEndingHere);
	  }
	  else
		 maxEndingHere = 1;
	  
	 
  }
  
  printf(" %d \r\n", maxEndingSoFar);

}*/

int main()
{
  int retVal = maxSubarrayProduct(array, sizeof(array)/sizeof(int));
  printf("max Product = %d\n", retVal);
  return 0;
}