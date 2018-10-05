#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
//["LRUCache","put","put","get","put","get","put","get","get","get"]
//[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]
typedef struct node_t
{
   int key;
   int value;
   int lruIdx;
}node;

typedef struct {
    node **cacheArray;
    int capacity;
    int totalElemCount;
    int accessCount;
} LRUCache;

void swap(int *a, int *b)
{
   char temp = *a;
    *a = *b;
    *b = temp;
}

LRUCache* lRUCacheCreate(int capacity) 
{
	int i = 0;
    LRUCache* tmp = malloc(sizeof(LRUCache));
    tmp->capacity = capacity;
    tmp->cacheArray = malloc(sizeof(node*) * capacity);
    tmp->totalElemCount = 0;
    tmp->accessCount = 0;
	
	for(i=0; i<capacity;i++)
	{
		tmp->cacheArray[i] = NULL;
	}
    return tmp;
}

int lRUCacheGet(LRUCache* obj, int key) 
{
    int i = 0;
    int N = obj->capacity;
   
    printf("get(%d)\r\n",key);
    for(i=0; i<N; i++)
    {
        if(obj->cacheArray[i])
        {       
            if(obj->cacheArray[i]->key == key)
            {
                obj->accessCount++;
                obj->cacheArray[i]->lruIdx =  obj->accessCount;
                return obj->cacheArray[i]->value;
            }
        }
    }
    
    return -1;
}

void lRUCachePut(LRUCache* obj, int key, int value) 
{
    int i = 0;
    int N = obj->capacity;
    int lruIdx = -1;
    int findIdx = -1;
	int lruLocation = -1;
    printf("put(%d, %d)\r\n",key,value);
    for(i=0; i<N; i++)
    {
        if(obj->cacheArray[i])
        {
            if((lruIdx > obj->cacheArray[i]->lruIdx) || (lruIdx == -1))
            {
				lruLocation = i;
                lruIdx = obj->cacheArray[i]->lruIdx;
            }
            
            if(obj->cacheArray[i]->key == key)
            {
                obj->accessCount++;
                obj->cacheArray[i]->lruIdx =  obj->accessCount;
                obj->cacheArray[i]->value = value;
                return;
            }
        }
        else if(findIdx == -1)
		{
            findIdx = i;
		}
    }
	
	if(obj->totalElemCount >= N)
    {
		printf("cache full...removing LRU at %d\r\n",lruLocation);
		findIdx = lruLocation;
	}
	printf("putting  (%d ,%d) in idx = %d \r\n\r\n",key,value,findIdx);
	obj->accessCount++;
    obj->cacheArray[findIdx] = malloc(sizeof(node));
    obj->cacheArray[findIdx]->key = key;
    obj->cacheArray[findIdx]->lruIdx =  obj->accessCount;
    obj->cacheArray[findIdx]->value = value;
	obj->totalElemCount++;
    return;	
    
}

void lRUCacheFree(LRUCache* obj) {
    
    node *ptr = obj->cacheArray[0];
    int i = 0;
    int N = obj->capacity;
    for(i=0; i<N; i++)
    {
        ptr = obj->cacheArray[i];
        
        if(ptr)
        {
            free(ptr);
        }
        
    }
    free(obj);
    
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * struct LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 * lRUCachePut(obj, key, value);
 * lRUCacheFree(obj);
 */
 
int main()
 {
	 LRUCache *ptr = lRUCacheCreate(2);
	 lRUCachePut(ptr, 1, 1);
	 lRUCachePut(ptr, 2, 2);
	 printf(" key  =%d, value = %d\r\n", 1,lRUCacheGet(ptr,1));
	 printf(" key  =%d, value = %d\r\n", 2,lRUCacheGet(ptr,2));
	 lRUCachePut(ptr, 3, 3);
	 printf(" key  =%d, value = %d\r\n", 2,lRUCacheGet(ptr,2));
	 lRUCachePut(ptr, 4, 4);
	 printf(" key  =%d, value = %d\r\n", 1,lRUCacheGet(ptr,1));
	 printf(" key  =%d, value = %d\r\n", 3,lRUCacheGet(ptr,3));
	 printf(" key  =%d, value = %d\r\n", 4,lRUCacheGet(ptr,4));
	 return 0;
 }
	 