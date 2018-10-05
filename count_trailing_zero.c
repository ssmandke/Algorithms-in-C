

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define CHAR_BIT 8
#define MIN(a,b) (a<b? a:b)
#define MAX(a,b) (a>b? a:b)


int retCountTrailingZero(unsigned int w)
{
  unsigned int v = w;  // input to count trailing zero bits
  int c;  // output: c will count v's trailing zero bits,
        // so if v is 1101000 (base 2), then c will be 3

  if (v)
  {
    v = (v ^ (v - 1)) >> 1;  // Set v's trailing 0s to 1s and zero rest
  
    for (c = 0; v; c++)
    {
      v >>= 1;
    }
  }
  else
  {
     c = CHAR_BIT * sizeof(v);
  }
  
  return c;
}
int main()
{
  printf("trailing zeros in 104 is %d ", retCountTrailingZero(104));
  return 0;
}
