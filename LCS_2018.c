#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a,b) (a>b? a:b)

int longestCommonSubsequence(char *a, char lenA, char *b, char lenB)
{
	char i,j;
	char **LCS = malloc(sizeof(char*) * lenA);
	
	for(i=0; i<lenB;i++)
	{
		LCS[i] = malloc(sizeof(char) * lenB);
	}
	
	for(i=0; i<lenA;i++)
	{
		for(j=0;j<lenB;j++)
		{
			if(a[i] == b[j])
			{
				LCS[i][j] = 1 + LCS[i-1][j];
			}
			else
			{
				LCS[i][j] = MAX(LCS[i-1][j], LCS[i][j-1]);
			}
		}
	}
	
	return LCS[lenA-1][lenB-1];
}

int main()
{
	return 0;
}