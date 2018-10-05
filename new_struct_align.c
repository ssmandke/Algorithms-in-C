

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct foo5 {
    char c;
    struct foo5_inner {
        char *p;
        short x;
    } inner;
}foo_5;


typedef struct foo6 {
    char c;
    struct foo6_inner {
        char *p;
        short x;
		long y;
    } inner;
	
	long z;
	double m;
}foo_6;

int main()
{
   printf("%d   %d and sizeof long is %d\n", sizeof(foo_5), sizeof(foo_6), sizeof(long));
   return 0;
}