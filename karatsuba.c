#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>     /* atoi */

void karatsuba_master(char *x, char *y, char *result, unsigned long strlen_max);
unsigned long  karatsuba(unsigned long x, unsigned long y);
unsigned long  ndigit(unsigned long  x, unsigned long  y);
unsigned long  leftHalf(unsigned long  x, unsigned long  n);
unsigned long  rightHalf(unsigned long  x, unsigned long  n);

#define MAX 128
#define max(a,b) (a>b?a:b)

int main()
{
 	unsigned long  x, y;
	char a_arr[MAX];
	char b_arr[MAX];
	char result_arr[MAX];
	unsigned long strlen_max = 0;
 	printf("Enter two numbers: ");
 	scanf("%s%s", &a_arr, &b_arr);
	strlen_max = max(strlen(a_arr) ,strlen(b_arr));

	char *resPtr ; //
    char *ptr = NULL;
    ptr = resPtr = malloc(max(strlen(a_arr) ,strlen(b_arr)) + 1);
	 *(ptr + (max(strlen(a_arr) ,strlen(b_arr)) + 1)) = '\0';

	if(strlen(a_arr) > strlen(b_arr))
	{
	  int count = strlen(a_arr) - strlen(b_arr);

	  while(count--)
	  {
		*ptr++ = '0';
	  }
	  
	  memcpy(ptr, b_arr, strlen(b_arr));
	} 
	else if ( strlen(a_arr) < strlen(b_arr))
	{
	  int count = strlen(b_arr) - strlen(a_arr);
	  
	  while(count--)
	  {
		*ptr++ = '0';
	  }
	  
	  memcpy(ptr, a_arr, strlen(a_arr));
	}
	
	printf("\r\nThe numbers are \r\n%s\r\n%s\r\n", a_arr,b_arr);
	printf("\r\nThe modified operand is %s\r\n", resPtr);
	printf("Max Digit Length = %d\r\n",strlen_max);
 	//printf("%d * %d = %d\n", x, y, karatsuba(x, y));
	karatsuba_master(a_arr, b_arr, result_arr, strlen_max);
	return 0;
}

void karatsuba_master(char *x, char *y, char *result, unsigned long strlen_max)
{
  int i = 0;
  char *ptrX =x;
  char *ptrY =y;
  char *ptrResult = result;
  unsigned int offset = sizeof(unsigned long);
  printf("strlen(ptrX) = %d\r\n",strlen(ptrX));
  unsigned long temp;
  //for(i=0; i<strlen_max; i++)
  {
	 unsigned long op_a = atoi(ptrX);// + strlen(ptrX) - offset);
	 unsigned long op_b = atoi(ptrY);// + strlen(ptrY) - offset);
	 unsigned long result = 0;
	 printf("a = %d, b= %d, Result = %u",op_a, op_b, result);

	 temp = karatsuba(op_a, op_b);
	 printf("output = %d", temp);
	 
  }
}

unsigned long  karatsuba(unsigned long  x, unsigned long  y)
{
 	if(x < 10 || y < 10)
 		return x * y;
 	
	unsigned long  n = ndigit(x, y) / 2;
 	
	unsigned long  a = leftHalf(x, n); // x = 10^n/2 * a + b
 	unsigned long  b = rightHalf(x, n);
 	unsigned long  c = leftHalf(y, n); // y = 10^n/2 * c + d
 	unsigned long  d = rightHalf(y, n);
 
	unsigned long  ac = karatsuba(a, c);
 	unsigned long  bd = karatsuba(b, d);
 	unsigned long  abcd = karatsuba((a + b), (c + d));
 
	return ac * pow(10, n * 2) 
			+ (abcd - ac - bd) * pow(10, n) 
			+ bd;
}
 
unsigned long  ndigit(unsigned long  x, unsigned long  y)
{
	unsigned long  xdigit = 0, ydigit = 0;
 	
	do
 	{
 		++xdigit;
 		x /= 10;
 	}
 	while(x);
 
	do
 	{
 		++ydigit;
 		y /= 10;
 	}
 	while(y);
 	
	return (xdigit > ydigit) ? xdigit : ydigit;
}
 
unsigned long  leftHalf(unsigned long  x, unsigned long  n)
{
 	return x / pow(10, n);
}
 
unsigned long  rightHalf(unsigned long  x, unsigned long  n)
{
 	return x % (unsigned long )pow(10, n);
}