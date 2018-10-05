
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int main()
{
  unsigned int w = 0x12345678;
  unsigned int z = 0;
  
  z = ((w >> 24) & 0xFF)   | \
      ((w >> 8)  & 0xFF00) | \
	  ((w << 8)  & 0xFF0000) | \
	  ((w << 24) & 0xFF000000) ;
      
  printf("0x%x and 0x%x \n",w,z);
  return 0;
}