
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CHAR_SIZE 8
#define MASK (1<<16)
#define BITCOUNT 4
#define LOWER_NIBBLE ((1<<BITCOUNT) - 1)
#define UPPER_NIBBLE ~((1<<BITCOUNT) - 1)

unsigned char nibbleSwap(unsigned char x)
{
	printf("\r\n mask = 0x%x ,lower nibble = 0x%x, upper nibble = 0x%x\r\n",  LOWER_NIBBLE, \
	                                                                        (x & LOWER_NIBBLE),\
																			(x & UPPER_NIBBLE));
    x = (x & LOWER_NIBBLE) << 4 | (x & UPPER_NIBBLE) >> 4;
	return x;
}

char bitReversal(char x)
{
  char result = 0;

  while(x)
  {
    result<<=1;
    
    if(x&0x01) 
    {
       result|=0x01;
    } 
    
    x>>=1;   
  }
  
  return result;
}

void printBinary(char x)
{
	char *str = malloc(sizeof(CHAR_SIZE));
	char idx = 0;
	char j = 0;
	while(x)
	{
		if(x&0x01)
			str[idx]=1;//printf("1");
		else
			str[idx]=0;//printf("0");
		x>>=1;
		idx++;
	}
	idx--;
	while(idx>=0)
	{
		printf("%d",str[idx]);
		idx--;
	}
	//printf("%s\r\n",str);
	printf("\r\n");
}

char *c[] = {"GeksQuiz", "MCQ", "TEST", "QUIZ"};
char **cp[] = {c+3, c+2, c+1, c};
char ***cpp = cp;

int main()
{ 
  int tmp = 10 + 20 * 30 ;
  int a[5] = {1,2,3,4,5};
  int i = 5;
  int w = ++i + ++i;
  i = 5;
  int m = ++i + ++i + ++i;
  int p = 1;   //000000000......01
   printf("p = %d\r\n",p);
p = p << 31; //100000000......00
printf("p = %d 0x%x\r\n",p,p);
p = p >> 31; //111111111......11 (Everything is filled with 1s !!!!!) 
printf("p = %d\r\n",p);
  printf("0x%x   0x%x  0x%x  \r\n",MASK, MASK-1, ~(MASK-1));
  
  printf("%d\r\n",w);
  printf("%d\r\n",m);
  int *ptr = (int*)(&a+1);
  printf("%s ", **++cpp);
  printf("%s ", *--*++cpp+3);
  printf("%s ", *cpp[-2]+3);
  printf("%s ", cpp[-1][-1]+1);
  printf("%d %d\r\n", *(a+1), *(ptr-1));
  ptr=(int*)&a;
  printf("ptr=&a 0x%p 0x%p\r\n", ptr, (int*)(&a+1));
  printf("tmp = %d\r\n",tmp);
  char x = 12;
  printBinary(12);
  char z = bitReversal(x);
  printf(" %d \r\n",z);
  printBinary(z);
  printBinary(13);
  unsigned char k = nibbleSwap(13);
  printf("\r\nNibbleSwap of 13 is 0x%x (%d)\r\n",k,k);
  return 0;
}