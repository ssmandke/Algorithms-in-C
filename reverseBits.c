
#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

unsigned int  reverseBits(unsigned int  n) {
    
    unsigned int  result = 0;
    unsigned int count = sizeof(n) * 8;
	
    while(count)
    {
        result<<=1;
        
        if(n&0x01)
            result |=0x01;
        n>>=1;
		count--;
    }
    
    return result;
    
}

int main()
{
   unsigned int res = reverseBits(43261596);
   printf("43261596 reversed bits gives %d\r\n",res);
   return 0;
}