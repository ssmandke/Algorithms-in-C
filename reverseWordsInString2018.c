#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include<string.h>

#define bool char
#define true 1
#define false 0
#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)


char str[]= "The sky is blue";
	
void swap(char *a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void reverseWords(char *s) {
    
    int stringLen = strlen(s);
    int left = 0;
    int right = stringLen-1;
    int count = stringLen/2;
    int i = 0;
    
    while((i < count) && (right > 0))
    {
        swap(&s[left], &s[right]);
        i++;
        left++;
        right--;
    }
    
    left = 0;
    right = 0;
  
    while(left < stringLen)
    {

        while(s[left] == ' ')
            left++;

        right = left;
        
        while((s[right] !=' ') && (s[right] != '\0'))
            right++;

		char tmp = right;
		
		right = right - 1;
        
		while( left <  right)
        {			
            swap(&s[left], &s[right]);           
            left++;
            right--;
        }
		
		left = right = tmp;
        
    }
    
    printf("%s\r\n",s);
    
}

int main()
{
	reverseWords(str);
	return 0;
}