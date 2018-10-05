#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a,b) (a<b? a:b)
#define MAX(a,b) (a>b? a:b)

// A structure for building 
typedef struct Building_t
{ 
    int left;  // x coordinate of left side 
    int ht;    // height 
    int right; // x coordinate of right side 
}Building;

typedef struct Strip_t
{
	int left;
	int ht;
}Strip;

typedef struct SkyLine_t
{ 
    Strip *arr;   // Array of strips 
    int capacity; // Capacity of strip array 
    int n;   // Actual number of strips in array 
}Skyline;

Skyline *newSkyline (int cap)
{
	Skyline *tmp = malloc(sizeof(Skyline));
	tmp->capacity = cap;
    tmp->arr = malloc(sizeof(Strip) * cap);//new Strip[cap]; 
    tmp->n = 0; 
}

Skyline* mergeSkyline(Skyline *left, Skyline *right)
{
	//Skyline* result = 
}

void append(Skyline *res , Strip *st) 
{ 
    // Check for redundant strip, a strip is 
    // redundant if it has same height or left as previous 
	int n = res->n;

    if (n > 0 && res->arr[n-1].ht == st->ht) 
       return; 
    if (n > 0 && res->arr[n-1].left == st->left) 
    { 
       res->arr[n-1].ht = MAX(res->arr[n-1].ht, st->ht); 
       return; 
    } 
  
    res->arr[n] = *st; 
    n++; 
	res->n = n;
}

Skyline* findSkyline(Building arr[], int left, int right)
{
	if(left == right)
	{
		Skyline *res = newSkyline(2);
		Strip *ptr1  = malloc(sizeof(Strip));
		ptr1->arr[0].left = arr[left].left;
		ptr1->arr[0].ht   = arr[left].ht;
	    append(res, ptr1);
		Strip *ptr2  = malloc(sizeof(Strip));
		ptr1->arr[1].left = arr[left].right;
		ptr1->arr[1].ht   = 0;		
		append(res, ptr2);
	}
	
	int mid = (left + right)/2;
	Skyline *sleft = findSkyline(arr, left, mid);
	Skyline *sright = findSkyline(arr, mid+1, right);
	Skyline *mergedPtr = mergeSkyline(sleft, sright);
	
	return mergedPtr;
}


// drive program 
int main() 
{ 
    Building arr[] = {{1, 11, 5}, {2, 6, 7}, {3, 13, 9}, 
                      {12, 7, 16}, {14, 3, 25}, {19, 18, 22}, 
                      {23, 13, 29}, {24, 4, 28}}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    // Find skyline for given buildings and print the skyline 
    Skyline *ptr = findSkyline(arr, 0, n-1); 
    
    return 0; 
} 