#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

//for KMP, we find longest prefix that is also a suffix of the pattern

void computeLPSArray(char *pat, char M, char *lpsArr)
{
	int i = 0;
	int len = 0;
	
	for(i=0; i<M; i++)
	{
		lpsArr[i] = 0;
	}
	
	i = 1;
	
	while((i<M) && (len >=0))
	{
		if(pat[len] == pat[M])
		{
			len++;
			lpsArr[i] = len;
			i++;
		}
		else //for mismatch
		{
			if(len !=0)
			{
				len = lpsArr[len - 1];
			}
			else
			{
				lpsArr[i]=0;
				i++;
			}
		}
	}
}

void KMPSearch(char *txtArr, char N, char *patArr, char M, char *lpsArr)
{
	//KMP Search!!
	int i,j, len;
	i = j = len = 0;

	while(i<N)
	{
		if(txtArr[i] == patArr[j])
		{
			i++;
			j++;
			
			if(j==M)
			{
				printf("\r\nMatch found at %d\r\n", j);
				j = lpsArr[j-1];
			}
		}
		else // if(txtArr[i] != patArr[j])
		{
			if(j!=0)
			{
				j = lpsArr[j-1];
			}
			else
				i = i + 1;			
		}
	}
}

int main()
{
	char *txt = "ABABDABACDABABCABAB";
    char *pat = "ABABCABAB";

    char M = strlen(pat);
    char N = strlen(txt);
	
	printf("Text string    = %s, len = %d\r\n", txt, N);
    printf("Pattern string = %s, len = %d\r\n", pat, M);

    char *lps = malloc(sizeof(char) * M);
    computeLPSArray(pat, M, lps);
    KMPSearch(txt,N,pat,M,lps);
}