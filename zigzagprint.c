#include<stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define MIN(a,b) (a<b? a:b)
#define MAX(a,b) (a>b? a:b)

#define bool char
#define TRUE 1
#define FALSE 0

char str[] = "PAYPALISHIRING";

int main()
{
  int i,j,k;
  i = j = 0;
  int lenOfStr = strlen(str);
  char tmp[lenOfStr][lenOfStr];
  char *ptr = str;
  int numRow = 4;
  char count = 0;
  char middleElementCount = numRow - 2;
  char rowCount = 0;
  char direction = 0;
  
  for(i=0;i<lenOfStr;i++)
  {
	  for(j=0;j<lenOfStr;j++)
	  {
		  tmp[i][j]='\0';
	  }
  }
  
  i=j=0;
  
  while(*ptr!='\0')
  {
	  printf(" %c ",*ptr);
	  	
	  if(direction == 0)
	  {
		  tmp[i][j] = *ptr;		  
		  printf("(%d, %d)\r\n", i,j);
		  i++;
		  rowCount++;
		  
		  if(rowCount == numRow)
		  {
			  direction = 1;
			  j=j+1;
			  i=i-2;
			  rowCount = 0;
			  printf("changing direction ... (%d, %d)\r\n", i,j);
		  }
	  }
	  else
	  {
		  printf("-->\r\n");
		  rowCount++;
		  printf("(%d, %d)\r\n", i,j);
		  tmp[i][j] = *ptr;
		  i--;
		  j++;

		  if(rowCount == middleElementCount)
		  {
			  direction = 0;
			  i=0;
			  printf("changing direction ... (%d, %d)\r\n", i,j);
			  rowCount = 0;
			  //j=j+1;
		  }
	  }
	  
	  ptr++;	  
  }
  
  printf("\r\n  \r\n");
  for(i=0;i<lenOfStr;i++)
  {
	  for(j=0;j<lenOfStr;j++)
	  {
		 //if(tmp[i][j] !='\0')
		 {
		   printf(" %c ",tmp[i][j]);		   
		 }
	  }
	  printf("\r\n");
  }
  return 0;
}