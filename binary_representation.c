

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define CHAR_BIT 8
#define MIN(a,b) (a<b? a:b)
#define MAX(a,b) (a>b? a:b)

void printBinary(char num)
{
   char tmp = num;
   char arr[8];
   char i = 7;
   memset(arr,0,8);
   
   while(tmp)
   {
      if(tmp&0x01)
	  {
	    arr[i] = 1;
	  }
	  else
	  {
	    arr[i] = 0;
	  }
      i--;
	  tmp>>=1;
   }
   
   for(i=0; i<8;i++)
   {
	  printf("%d",arr[i]);
   }
   printf("\r\n");
}

int main()
{
  printBinary(104);
  return 0;
}