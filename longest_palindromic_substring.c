#include<stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define MIN(a,b) (a<b? a:b)
#define MAX(a,b) (a>b? a:b)

#define bool char
#define TRUE 1
#define FALSE 0

int longest_palindromic_substring_DP(char *T, char length_of_T)
{
	char dp_matrix[length_of_T][length_of_T];
	char i,j,k;
	char longestPalindromeSubstringLen  = 1;
	char startOfSubString = 0;
	int retVal = -1;
	
	//i to j is palindrome if i+1 to j-1 is a palindrome..
	for(i=0;i<length_of_T;i++)
	{
		for(j=0;j<length_of_T;j++)
		{
			dp_matrix[i][j]=FALSE;
		}		
	
	   dp_matrix[i][i]=TRUE;	   
	}
	
	for(i=2; i<=length_of_T ;i++)
	{
		for(j=0; j< length_of_T - i + 1; j++)
		{
			k = j+i-1;
			
			if((T[j] == T[k]) && (dp_matrix[j+1][k-1] == TRUE))
			{
				dp_matrix[j][k] = TRUE;

                if(i> longestPalindromeSubstringLen)
                {
					startOfSubString = j;
					longestPalindromeSubstringLen=i;
				}					
			}
		}
	}
	retVal=0;
	for(k=j; k<i;k++)
	{
		printf("%c",T[k]);
		retVal++;
	}
	printf("\r\n");
return retVal;
}
  
int manacher(char *T, char length_of_T, char *P)
{
	int C = 0, R = -1, rad; 
    
	for (int i = 0; i < length_of_T; ++i) 
	{
       // find the corresponding letter in the palidrome subString
       int iMirror = C - (i - C);

       if (i <= R) //does i lie within R that is within the boundary of the main palindrome..
	   {
		  //which means that palindrome with center  can't go beyond the original palindrome, so apply the Mirror Property directly
          rad = MIN(P[iMirror], R-i);  
       } 
	   else 
	   {
          rad = 0; 
       }
       // Try to extend
       while (i+rad < length_of_T && i-rad >= 0 && T[i-rad] == T[i+rad]) 
	   {
         rad++; 
       }
          
	   P[i] = rad;
       
	   if (i + rad - 1 > R) //Palindromic length has gone beyond right boundary...updates center and right boundary..
	   {
         C = i; //i is trying to find the next center of the main palindrome..
         R = i + rad - 1; 
       }
    }
}
int main()
{
  //Longest Palindromic substring...not subsequence
  char *str = "ABABABA";
  char *P = malloc(sizeof(str)*2 -2); //Create a string twice the length of original string..this is new string and we expand palindromic string at each point
  printf("\r\n Longest palindromic substring with manacher = %d\r\n",manacher(str, strlen(str),P));
  printf("\r\n Longest palindromic substring with DP       = %d\r\n",longest_palindromic_substring_DP(str, strlen(str)));
  
  return 0;
}