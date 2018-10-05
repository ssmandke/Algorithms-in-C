#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define bool char
#define true 1
#define false 0


void swap(char *x, char *y)
{
  char temp = *x;
  *x = *y;
  *y = temp;
}

bool isSubsetSum(char set[], char len, char sum)
{
	// The value of subset[i][j] will be true if there is a 
    // subset of set[0..j-1] with sum equal to i
  bool subset[len+1][sum+1];
  int i = 0;
  int j = 0;
   // If sum is 0, then answer is true
   for ( i = 0; i <= len; i++)
      subset[i][0] = true;
  
  // If sum is not 0 and set is empty, then answer is false
    for (i = 1; i <= sum; i++)
      subset[0][i] = false;
  
  // Fill the subset table in botton up manner
     for (i = 1; i <= len; i++)
     {
       for (j = 1; j <= sum; j++)
       {
         //first copy the data from the top
         subset[i][j] = subset[i-1][j];
		 
		 //If subset[i][j]==false check if can be made
		  //Here j represents the current sum,
         if (j>=set[i-1])
		 {
           subset[i][j] = subset[i-1][j] || 
                                 subset[i - 1][j-set[i-1]];
           //printf("\r\n%d %d", j, set[i-1]);
		 }
       }
     }
	 for ( i = 0; i <= len; i++)
     {
       for (j = 0; j <= sum; j++)
       {
		   printf("%d ", subset[i][j]);
	   }
	   printf("\r\n");
	 }
	 return subset[len][sum];
}

// Driver program to test above function
int main()
{
  char set[] = {3, 34, 4, 12, 5, 2};
  char sum = 43;
  char n = sizeof(set)/sizeof(set[0]);
  printf("\r\n size of set = %d\r\n", n);
  if (isSubsetSum(set, n, sum) == true)
     printf("Found a subset with given sum");
  else
     printf("No subset with given sum");
  return 0;
}