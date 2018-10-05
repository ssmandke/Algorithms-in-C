#include <stdio.h>
#include <string.h>
#include <stdlib.h>
static char hashtable[26];
char array[] = "ABCDAFGHICE";
char len = sizeof(array) - 1;

int longestSubStringWithoutRepetition(char arr[], char len)
{
	int i = 0;
	int counter = 0;
	int start = 0;
	int maxLen = 0;
	int maxStart = 0;
	int maxEnd = 0;
	printf("String = %s, len = %d\r\n",arr,len);
	for(; i<len; i++)
	{
	   printf("%c ",arr[i]);
	   
       if(hashtable[arr[i]-'A']!=0)
	   {
		   //repeat found
		   printf(" %c \r\n",hashtable);
		   maxLen =  (maxLen > counter)?maxLen:counter;
		   maxStart = start;
		   maxEnd = i;
		   hashtable[arr[i]] = 0;
		   start++;
		   //counter = 0;
	   }
	   else
	   {
	       printf("-> %c \r\n",arr[i]);
	       hashtable[arr[i]-'A'] = 1;
		   counter++;
	   }
	 }
      return maxLen; 	       
	
}

int main ()
{
  unsigned int x = 0x76543210;
  char *c = (char*) &x;
 
  printf ("*c is: 0x%x\n", *c);
  if (*c == 0x10)
  {
    printf ("Underlying architecture is little endian. \n");
  }
  else
  {
     printf ("Underlying architecture is big endian. \n");
  }
  printf(" Longest Substring Length = %d\r\n ",longestSubStringWithoutRepetition(array, len));
  
  //string copy
  //while(*s++ = *t++);
  return 0;
}