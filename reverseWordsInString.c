#include<stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define MIN(a,b) (a<b? a:b)
#define MAX(a,b) (a>b? a:b)

#define bool char
#define TRUE 1
#define FALSE 0

char string[] = "Sarang Mandke is an Engineer";

char* reverseWordsInString(char *ptrToString, char stringLen)
{
   int i = stringLen;
   int j = 0;
   printf("%s\r\n",ptrToString);
   
   while(i>0)
   {
     while(ptrToString[i]!=' ')
     { 
        i--;
		if(i== -1)
		{
			break;
		}
		//printf("%c", ptrToString[i]);
     } 
     j=i+1;
     i--;
     //printf("(%d, %d)\r\n",i,j);
     while(ptrToString[j]!=' '&& ptrToString[j]!='\0')
     {
        printf("%c", ptrToString[j]);
        j++;
     }
	 
	  printf(" ");
   }
   printf("\r\n");
   return ptrToString;  
}

int main()
{
   char *tmp = reverseWordsInString(string, sizeof(string)-1);
   //printf("%s\r\n",tmp);
   return 0;
}
