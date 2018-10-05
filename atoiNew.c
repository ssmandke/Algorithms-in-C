
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int atoiNew(char *str, char len)
{
  int result = 0;
  char *ptr = str;
  printf("%s\r\n",ptr);

  while(*ptr != '\0')
  {
    result = result * 10;
    result+= (*ptr - '0');
    ptr++;
  }
  
  return result;
}

int main()
{
  char *tmpString = "125";
  printf("%s\r\n",tmpString);
  printf("%d\r\n",atoiNew(tmpString,3));
  return 0;
}