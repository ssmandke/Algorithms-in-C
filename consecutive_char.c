//You are given a string that may contain consecutive, duplicate characters (e.g.: "aaabcdddefffffggaaa"). 
//Can you count the number of times characters appear more than 3 times in consecutive order (answer: 4)? 
//Can you return the max-length run of consecutive, duplicate characters (answer: 5)? 
//Can you print the input where you print up to N consecutive characters in a row,
// but no more (e.g.: if N=2, then the answer would be: "aabcddeffggaa"). Can you reverse the string in-place?
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

static char hashtable[26];

// User defined sizeof macro
# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type))

int main()
{
	int  arr[] = {1, 2, 3, 4, 5, 6};
    int size = *(&arr + 1) - arr;
	printf("Size = %d\r\n", size);
	return 0;
}