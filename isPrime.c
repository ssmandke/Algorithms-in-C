#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define bool char
#define true 1
#define false 0

/*function is_prime(n)
     if n ≤ 1
        return false
     else if n ≤ 3
        return true
     else if n mod 2 = 0 or n mod 3 = 0
        return false
     let i ← 5
     while i * i ≤ n
        if n mod i = 0 or n mod (i + 2) = 0
            return false
        i ← i + 6
     return true */

bool isPrime(int n)
{
   int i = 0;
   
   if(n<=1)
	   return false;
   else if (n<=3)
	   return true;
   else if ((n%2 == 0) || (n%3 == 0))
	   return false;
   
   for(i=5 ;(i * i)< n;i=i+6) //since primes are of type 6k+i and max we need to check is till squareroot of n
   {
	   if((n%i==0) || (n%(i+2) == 0))
		   return false;
   }
   return true;
}
	
int main()
{
  char x = isPrime(13);
  printf("The number is %d\r\n", (x>0?true:false));
  x = isPrime(24);
  printf("The number is %d\r\n", (x>0?true:false));
  return 0;
}