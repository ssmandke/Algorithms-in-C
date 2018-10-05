
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define bool char
#define true 1
#define false 0

#define MIN(a,b) (a<b?a:b)
#define MAX(a,b) (a>b?a:b)

char S[] = "ADOBECODEBANDC";
char T[] = "ABC";

static char hashtable[26];

int main()
{
	int i = 0;
	int j = 0;
	int len1 = strlen(S);
	int count = -1;
	
	for(i=0; i< len1; i++)
	{
		if(S[i] == 'A')
		{
			hashtable['A'] = i;
			count++;
		}
		else if(S[i] == 'B')
		{
			hashtable['B'] = i;
			count++;			
		}
        else if(S[i] == 'C')
		{
			hashtable['C'] = i;
			count++;			
		}
		
		if(count >= 3)
		{
			int min = MIN(hashtable['A'], MIN(hashtable['B'],hashtable['C']));
			int max = MAX(hashtable['A'], MAX(hashtable['B'],hashtable['C']));
			int len = max - min;
			count   = MIN(len, count);
		}
	}
	
	printf("Min Length = %d\r\n", count);
}