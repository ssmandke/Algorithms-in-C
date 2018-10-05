#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

char str1[] ="anagram";
char str2[] ="nagaram";
void swap(char *x, char *y)
{
  char temp = *x;
  *x = *y;
  *y = temp;
}

void permute(char x[], char left, char right)
{
  int idx = 0;
  if(left == right)
  {
	  if(strcmp(x, str2) == 0)
	  {
		  printf("%s\r\n",x);
		  exit(0);
	  }
    
  }
  else
  {
    
	for(idx = left; idx < right; idx++)
	{
		//printf("\r\nXXX");
		//printf("%s",x);
		swap(&x[idx], &x[left]);
		permute(x, left+1, right);
		swap(&x[idx], &x[left]);
	}
  }
}

int main()
{
  permute(str1, 0, sizeof(str1)-1);
  printf("strcmp gives for ab and ba as %d\r\n",strcmp("ab","ba"));
  return 0;
}