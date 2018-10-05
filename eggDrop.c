
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX(a,b) (a>b? a:b)
#define MIN(a,b) (a<b? a:b)

// for N floors and K eggs

int eggDropRecursive(int n, int k)
{
	if(n==0 || n==1)
		return n; // return no of floors if the floor count is 1 or 0;
	
	if(k==1)
		return n; //With 1 egg..we traverse all floors....
	
	int x = 0;
	int minAttempts = 9999;
	
	// Attempt to solve this for all floors..
	for(x=1 ; x <= n; x++)
	{
		int res = MAX(eggDropRecursive(n-x, k), eggDropRecursive(x-1, k-1));
		minAttempts = MIN(minAttempts, res);
	}
	
	return 1 + minAttempts;
}
int main() 
{ 
    int n = 10, k = 2; 
    printf ("\nMinimum number of trials in worst case with %d eggs and "
             "%d floors is %d \n", n, k, eggDropRecursive(n, k)); 
    return 0; 
} 
