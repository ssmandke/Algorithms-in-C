#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

void intersection(char arrA[], char lenA, char arrB[], char lenB)
{
	char totalLen = lenA+lenB;
	char i,j;
	
	while((i<lenA) && (j<lenB))
	{
		if(arrA[i] < arrB[j])
		{
			i++;
		}
		else if (arrA[i] > arrB[j])
		{
			j++;
		}
		
		if(arrA[i] == arrB[j])
		{
			printf(" %d ",arrA[i]);
			i++;
			j++;
		}
	}
	
	printf("\r\n");
}

int main()
{
  char arrA[]= {1,3,5,6,7,9,10,11,13,15};
  char arrB[]= {2,4,6,8,9,11,13,14,17,19};
  intersection(arrA, sizeof(arrA)/sizeof(char), arrB, sizeof(arrB)/sizeof(char));
  return 0;
}