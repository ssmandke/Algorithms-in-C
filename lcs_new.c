#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>     /* atoi */

// x, y are the sequences../ test strings
char *x = "ABAEDC";
char *y = "BACBAD";
//char *y = "CECEAD";
//char *y = "DBADAA";


int LCS_arr[7][7];

void LCS (char *x, char *y);

#define MAX(a,b) (a>b? a:b)

   int lcs_recursive_length(char * A, char * B)
    {
	if (*A == '\0' || *B == '\0') return 0;
	else if (*A == *B) return 1 + lcs_recursive_length(A+1, B+1);
	else return MAX(lcs_recursive_length(A+1,B), lcs_recursive_length(A,B+1));
    }
	
int main()
{
  int i = 0;
  int j = 0;
  int maxLCSLen = 0;
  char *xPtr = x;
  char *yPtr = y;
  
  for(i=1; i<7; i++)
  {
	//printf("\r\nloopA = %c", *xPtr);
	yPtr = y;
	for(j=1; j<7; j++)
	{
		//printf(" loopB = %c", *yPtr);
		if(*xPtr == *yPtr)
		{
		  LCS_arr[i][j] = 1 + LCS_arr[i-1][j-1];
		  printf("\r\nchar = %c, %c , MAXLEN = %d\r\n", *xPtr,*yPtr,maxLCSLen);
		}
		else
		{
		  LCS_arr[i][j] = MAX(LCS_arr[i-1][j],LCS_arr[i][j-1]);
		}
		
		if(LCS_arr[i][j] > maxLCSLen)
		{
		  maxLCSLen = LCS_arr[i][j];
		}
		
		yPtr++;
	}
	
	xPtr++;
  }
     
  printf("\r\nStrings are %s, %s and Length of LCS is %d \r\n",x,y,maxLCSLen);
  return 0;
}
