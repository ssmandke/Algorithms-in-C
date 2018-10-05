#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define LOW_NIBBLE   0x0F
#define UPPER_NIBBLE 0xF0
#define NIBBLE_BITSHIFT_CNT 4
#define EVEN_BITMASK 0x55555555
#define ODD_BITMASK  0xAAAAAAAA
#define CHAR_BIT 8


void swapNibble(int *a)
{
  int temp = *a;

  temp = (temp & LOW_NIBBLE) << NIBBLE_BITSHIFT_CNT  | ((temp & UPPER_NIBBLE) >> NIBBLE_BITSHIFT_CNT) & LOW_NIBBLE;

  *a = temp;  
}

void swapEvenOddBits(int *b)
{
   int temp = *b;
   
   temp = (temp & EVEN_BITMASK) << 1 | ((temp & ODD_BITMASK) >> 1 & EVEN_BITMASK);
   
   *b = temp;   
}



void reverseBit(unsigned char val)
{
  unsigned char temp = val;
  unsigned char result = 0;
  unsigned char count = CHAR_BIT; // 8
 
  while(count)
  {
    result<<=1;
    
    if(temp & 0x01) 
    {
       result |=0x01;
    }
    
    temp>>=1;
    
    count--;
  }

  printf("reversed value of 0x%x is 0x%x\r\n", val, result);  
}


int main()
{
  int x = 12; // 1100 in binary

  printf("0x%x with nibble swap",x);
  swapNibble(&x);
  printf(" gives 0x%x\r\n",x);
 
  x = 0x12123434;
  
  printf("\r\n0x%x with odd even bit swap",x);
  swapEvenOddBits(&x);
  printf(" gives 0x%x\r\n",x);
  reverseBit(0x55);
  return 0;
} 