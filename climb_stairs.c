#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//int *fib = NULL;

int climbStairs(int n) 
{
/*	
    if(fib == NULL)
	{		
		fib = malloc(sizeof(int) * n);
		memset(fib, 0, n);
	}
	*/
    static int fib[100];	
    
    if(n==1)
    {
        fib[1] = 1;
        return fib[1];
    }
    else if(n==2)
    {
        fib[2] = 2;
        return fib[2];
    }
        
    if(fib[n]!=0)
    {
        return fib[n];
    }
    
    fib[n-1] = climbStairs(n-1);
    fib[n-2] = climbStairs(n-2);
    fib[n] = fib[n-1] + fib[n-2];
	printf("Answer is %d\r\n",fib[n]);
    return fib[n];
    
}

int main()
{
   printf("climb stairs/fibonacci is %d\r\n",climbStairs(11));
   return 0; 
}