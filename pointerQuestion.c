#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_t
{
  struct node_t *next;
  char data;
} node;

typedef union test_t
{
   int x;
   char y;
   short z;
   long w;
   long long a;
}test;
 
test *ptr   = (test *)0x12345678;
test *ptr1  = (test *)0x9761;

int main()
{
	char array[35];
	char *tmp = (char *)&array[0];
	int arr[] = { 3, 5, 6, 7, 9 };
    int *p = arr;
    int (*ptr2)[5] = &arr;
	/*
	decltype(p) == int *, sizeof(int *) == 4
    decltype(ptr) == int[5] *, sizeof(int[5] *) == 4
    decltype(*ptr) == int[5], sizeof(int[5]) == 5 * sizeof(int) == 5 * 4 == 20
    Note that in your particular platform, sizeof(T *) == 4 for any type T.*/

	printf("sizeof(p) = %lu, sizeof(*p) = %lu\n", sizeof(p), sizeof(*p));
    printf("sizeof(ptr2) = %lu, sizeof(*ptr2) = %lu\n", sizeof(ptr2), sizeof(*ptr2));
	
	/*sizeof(char *) is the size of the pointer, so normally 4 for 32-bit machine, and 8 for 64-bit machine.
      sizeof an array, on the other hand, outputs the size of the array, in this case, 20*sizeof(char) = 20*/
	  
	  
    printf("print with format p = %p\r\n", ptr);
	printf("print with format x = %x\r\n", ptr);
	printf("print with format for sizeof-tmp is sizeof   = %d\r\n", sizeof(tmp));
	printf("print with format for sizeof-*tmp is sizeof object pointer to which is a char..  = %d\r\n", sizeof(*tmp));
	printf("print with format for sizeof-ptr   = %d\r\n", sizeof(ptr));
	printf("print with format for sizeof-*ptr  = %d\r\n", sizeof(*ptr));	
	printf("print with format for &ptr->y = %d\r\n", sizeof(&ptr->y));
	printf("print with format for sizeof-ptr for 0x9761  = %d\r\n", sizeof(ptr1));
	printf("print with format for sizeof-*ptr for 0x9761 = %d\r\n", sizeof(*ptr1));
    printf("sizes are char = %d, short = %d, int = %d, long = %d, long long = %d\r\n", sizeof(char),sizeof(short),sizeof(int),sizeof(long),sizeof(long long));
	return 0;
}