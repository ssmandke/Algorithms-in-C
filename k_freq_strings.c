

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include<string.h>

#define bool char
#define true 1
#define false 0
#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)

/**
 * Return an array of size *returnSize.
 //["i", "love", "leetcode", "i", "love", "coding"], k = 2
 * Note: The returned array must be malloced, assume caller calls free().
 */
char *arrayOfStrings[] = {"i", "love", "leetcode", "i", "love", "coding"};
char *tmpWords[] = {" ", " " , " ", " ", " ", " "};

void merge(char** words, char l, char mid, char r);

void mergeSort(char** words, char left, char right)
{
    if(left < right)
    {
        int mid = (left + right)/2;
        mergeSort(words,left, mid);
        mergeSort(words,mid+1, right);
        merge(words, left, mid+1, right);
    }
}

void merge(char** words, char l, char mid, char r)
{
    int leftEnd = mid;
    int left = l;
    int right = mid;
    int rightEnd = r;
    int i = 0;
    int j = 0;
	
	while((left < leftEnd) && ( right <= rightEnd))
    {
        if(strcmp(words[left], words[right]) <= 0)
        {
			tmpWords[i] = words[left];
            i++;
            left++;
        }
        else if(strcmp(words[left], words[right]) > 0)
        {
			tmpWords[i] = words[right];
            i++;
            right++;
        }
    }
    
    while(left < leftEnd)
    {
         tmpWords[i] = words[left];
         i++;
         left++;
    }
    
    while(right <= rightEnd)        
    {
         tmpWords[i] = words[right];
         i++;
         right++;    
    }
    j = 0;
	
	for(i=l; i < r+1 ; i++)
    {
		//printf("%s ", tmpWords[j]);
        words[i] = tmpWords[j];
        j++;
    }
	//printf("\r\n\r\n");
	
   
    //free(tmpWords);
}


char** topKFrequent(char** words, int wordsSize, int k, int* returnSize) 
{        
    int i = 0;
    mergeSort(words, 0, wordsSize-1);
    return words;
}

int main()
{
	int retSize = 0;
	
	int i = 0;
	int j = 0;
	
	for(i=0 ; i<6; i++)
	{
		printf("%s ",arrayOfStrings[i]);
	}
	
	printf("\r\n");
	topKFrequent(arrayOfStrings,6, 2, &retSize);
	for(i=0 ; i<6; i++)
	{
		printf("%s ",arrayOfStrings[i]);
	}
	
	printf("\r\n");
	
	for(i=0 ; i<6; i++)
	{
		if(arrayOfStrings[i] == arrayOfStrings[i+1])
		{
			tmpWords[j] = arrayOfStrings[i];
			j++;
			
			if(j==2)
				break;
		}
		
	}
	for(i=0 ; i<2; i++)
	{
		printf("%s ",tmpWords[i]);
	}
	return 0;
}