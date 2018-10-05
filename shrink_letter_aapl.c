#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//given 3 letters.. AB->C, AC->B, BC->A

char *string_check[6] =   {"AB", "BA", "BC", "CB", "AC", "CA"};

char str_val[6] = {'C','C','A','A','B','B'};

char input[] = "ABACB";
int counter = 0;
int main()
{
   int i = 0;
   
   for(i=0; i < sizeof(input)/sizeof(char); i++)
   {
	   if(i+1 < sizeof(input)/sizeof(char))
	   {
		   if(input[i]!=input[i+1])
		   {
			   char str[3];
			   int j = 0;

			   str[0] = input[i];
			   str[1] = input[i+1];
			   str[2] = '\0';
			   
			   for(j=0; j<sizeof(input)/sizeof(char); j++)
			   {
				   if(strcmp(string_check[j], str) == 0)
				   {
					   input[i] = '\0';
					   counter++;
					   input[i+1] = str_val[j];
				   }
			   }			   
		   }
	   }
   }
   
   printf("Counter = %d\r\n",counter);
   return 0;
}