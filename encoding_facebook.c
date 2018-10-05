#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a,b) (a<b? a:b)
#define MAX(a,b) (a>b? a:b) 
 
 // Given that letters are encoded like 1-A 2-B..Z-26 , 
 // Given a number , can you give the number of possible encodings possible? 
 // Given 123, it can be abc or lc,aw.

unsigned int x = 12;//1234;
char encodeTable[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

int numEncoding(unsigned int num)
{
   unsigned int result = 1;
   unsigned int i,j;
   
   for(i=0; i<9999; i++)
   {
	   unsigned int remainder1 =  num % 10;
	   unsigned int remainder2 =  num % 100;
	   unsigned int quotient   =  num / 10;
	   
	   if(remainder2 > 2 && remainder2 < 26)
	   {
		   printf("%d\r\n",remainder2);
		   result++;
	   }
	   
	   //result++;
	   
	   num = quotient;

       if(num == 0)
       {
		   break;
	   }		   
   }
   
   return result;
}

int main()
{
  int z  = numEncoding(x);
  printf("\r\nEncoding of x = %d  can be done in %d ways\r\n", x,z);
  return 0;
}