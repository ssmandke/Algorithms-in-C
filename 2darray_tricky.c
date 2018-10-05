

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int myMatrix[][4] = { {1,2,3,4} , {5,6,7,8} };

int main()
{
  int i = 0;
  int j = 0;
  
  for(i=0; i<2; i++)
  {
    for(j=0; j<4; j++)
	{
	  printf(" %d ", *(myMatrix[i] + j));	  
	  printf(" %d ", (*(myMatrix + i))[j]);
	  printf(" %d ", *((*(myMatrix + i)) + j));
	  printf(" %d ", *(&myMatrix[0][0] + 4*i + j));
	  printf(" --> 0x%p ", *(myMatrix + i + j));
	  printf(" 0x%p 0x%p 0x%p\r\n",(*(myMatrix + i)),  (*(myMatrix + i))[j], &myMatrix[i][j]);
	}
	printf("\r\n");
  }
  return 0;
}