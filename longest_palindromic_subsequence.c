#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define MIN(a,b) (a<b? a:b)
#define MAX(a,b) (a>b? a:b)

char arrStr[] = "agbdba";

int longest_palindromic_subsequence(char *P, char lenString)
{
   char dp_matrix[lenString][lenString];
   int i = 0;
   int j = 0;
   int k = 0;
   int N = lenString;
   
   for(i=0; i<N; i++)
   {
	   dp_matrix[i][i]=1;
	
	   for(j=0; j<N; j++)
	   {
		   if(i!=j)
		   {
			   dp_matrix[i][j]=0;
		   }		   
	   }	
   }
	for (i=2; i<=N; i++)
    {
        for (j=0; j<N-i+1; j++)
        {
            k = j+i-1;
            if (P[j] == P[k] && i == 2)
               dp_matrix[j][k] = 2;
            else if (P[j] == P[k])
               dp_matrix[j][k] = dp_matrix[j+1][k-1] + 2;
            else
               dp_matrix[j][k] = MAX(dp_matrix[j][k-1], dp_matrix[j+1][k]);
        }
    }

   for(i=0; i<N; i++)
   {
	   for(j=0; j<N; j++)
	   {
		   printf(" %d ", dp_matrix[i][j]);
	   }
	   printf("\r\n");
   }
   return 0;
}

int main()
{
  printf(" %s \r\n",arrStr);
  longest_palindromic_subsequence(arrStr,strlen(arrStr));
  return 0;
}