#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include<string.h>

#define bool char
#define true 1
#define false 0
#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)

char *LPS;

void computeLPS(char* ransomNote)
{
    int len = 1;
    int i = 0;
    
    LPS = malloc(sizeof(char) * strlen(ransomNote));
    
    while(i<strlen(ransomNote))
    {
    
        if(ransomNote[i] == ransomNote[len])
        {
            len++;
            ransomNote[i] = len;
            i++;
        }
        else
        {
            if(len>0)
                len = LPS[len-1];
            else
            {
                LPS[i] = 0;
                i++;
            }             
        }
    }
}

int KMPSearch(char *pat, char *txt)
{
    int i = 0;
    int j = 0;
    computeLPS(pat);
    
    while(j < strlen(txt))
    {
        if(pat[i] == txt[j])
        {
            i++;
            j++;
            
            if(i == strlen(pat))
                return 1;
            if(j == strlen(txt))
                return -1;
        }
        else
        {
            if(j!=0)
                j = LPS[j-1];
            else
            {
                i++;
            }
        }
    }
    
    return -1;
}

bool canConstruct(char* ransomNote, char* magazine) {
    if(ransomNote == NULL)
        return false;
    if(*(char*)ransomNote == "")
        return false;
    if(strlen(ransomNote) == 1)
    {
        if(strlen(magazine) == 1)
        {
            //printf(" %s , %s\r\n", *ransomNote, *magazine);
            if(*ransomNote != *magazine)
                return false;
        }
    }
    if(KMPSearch(ransomNote, magazine) == -1)
        return false;
    
    return true;

    
}

int main()
{
   if(canConstruct("","a") == false)
   {
      printf("false\r\n");
   }
   else
   {
      printf("true");
   }
   return 0;
}