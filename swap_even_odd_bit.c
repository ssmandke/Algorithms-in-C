#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ODD_MASK 0x55555555
#define EVEN_MASK 0xAAAAAAAA
// Swap even and odd bits in a number + maximum sum subarray
int main()
{
  unsigned int num = 23;//0x23;//0010 0011//---> 0x12345678; //expected is 00101011
  //Bitposition 0 is taken as bitposition 1 for this problem....
  //One right shift gives 0000 1011 //even locations moved to odd locations..
  //One left shift gives  0100 0110    //odd  locations moved to even locations..
  //Even Mask = 0xAAAAAAAA
  //Odd Mask  = 0x55555555
  //expected is           0010 1011
  unsigned int rightShift = (num >> 1) & ODD_MASK;
  unsigned int leftShift =  (num << 1) & EVEN_MASK;
  unsigned int answer = leftShift | rightShift;//((num >> 1) & 0x55555555) || ((num<<1) & 0xAAAAAAAA);
  printf("\r\nonly shift gives L = %d, R= %d\r\n", (num << 1), (num >> 1));
  printf("\r\nOriginal = 0x%x\r\nleftShifted = 0x%x\r\nrightShifted = 0x%x\r\nswapped with even odd bits is 0x%x\r\n", num, leftShift, rightShift,answer);

  return 0;
}