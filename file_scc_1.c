#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#define VERTEX_CNT 6//128///64//32//31//5
//#define bool char

typedef struct node
{
  unsigned int v; //vertex number
  struct node *next;
  struct node *nextStackPtr;
}node_t;

node_t *adjList[VERTEX_CNT];
node_t *adjListReversedGraph[VERTEX_CNT];
char visited[VERTEX_CNT];
node_t *head = NULL;
unsigned long countSCC = 0;

void insertIntoAdjacencyList(unsigned int y, node_t* iterator)
{
  node_t *iter = iterator;
  node_t *prev = NULL;
  node_t *ptr = malloc(sizeof(node_t));
  ptr->v = y;
  ptr->next = NULL;


  printf("\r\nAdjEnter v = %d, y = %d",iterator->v, y);
	
  while(iter!=NULL)
  {
	prev = iter;
	iter = iter->next;
  }

  printf("\r\nAdjExit");
  prev->next = ptr;
}

void stack_push(node_t* ptr)
{
  if(head == NULL)
  {
	 head = ptr;
  }
  else
  {
	 ptr->nextStackPtr = head;
	 head = ptr;
  }
}

int stack_pop()
{
  if(head)
  {
    node_t *tmp = head->nextStackPtr;
	int retVal = head->v;
	head = head->nextStackPtr;
	return retVal;
  }	  
}

unsigned int scc_size = 0;

void DFSUtil(int i, int listType)
{
    node_t *ptr;
	node_t *nodePtr;
	
   
    if(listType == 1)
    {
		ptr = adjList[i];		
	}
	else
	{
		ptr = adjListReversedGraph[i];
		scc_size++;
	}
	
	nodePtr = ptr;
    ptr = ptr->next;
    visited[i]=1; //Mark as visited
	
    while(ptr!=NULL)
    {
       i = ptr->v;
       
       if(!visited[i])
	   {
          DFSUtil(i, listType);
	   }
        
	   ptr = ptr->next;
    }
	
	if(listType == 1)
	{
		stack_push(nodePtr);
	}
}

int main(void)
{
    unsigned int v1,v2;
	unsigned long countEdges = 0;
    unsigned long idx  = 0;
	unsigned long jdx  = 0;

    FILE *fp;

    if((fp = fopen("C:\\Users\\smandke\\Documents\\SCC1.txt", "r+")) == NULL) {
        printf("No such file\n");
        return 1;
    }
    
	// Mark all the vertices as not visited (For first DFS)..also MALLOC for vertices
	for(idx = 0; idx < VERTEX_CNT; idx++)
	{
	  node_t *ptr = malloc(sizeof(node_t));
	  node_t *ptrRev = malloc(sizeof(node_t));
      ptr->v = idx;
	  ptr->next = NULL;
	  ptr->nextStackPtr = NULL;
	  visited[idx] = 0;
	  adjList[idx] = ptr;

	  adjListReversedGraph[idx] = ptrRev;
	  adjListReversedGraph[idx]->v = idx;
	  adjListReversedGraph[idx]->nextStackPtr = NULL;
	  adjListReversedGraph[idx]->next = NULL;
	}
	  	
    while (true) {
        int ret = fscanf(fp, "%u %u", &v1, &v2);
        if(ret == 2)
		{
            printf("\n%u \t %u", v1,v2);
		    countEdges++;
			insertIntoAdjacencyList(v2-1,adjList[v1-1]);
		}
        else if(errno != 0) {
            perror("scanf:");
            break;
        } else if(ret == EOF) {
            break;
        } else {
            printf("No match.\n");
        }
    }

    printf("\n\nEdge count = %d",countEdges);

	// Fill vertices in stack according to their finishing times
	for(idx = 0; idx < VERTEX_CNT; idx++)
	{
		if(visited[idx] == 0)
		{
			DFSUtil(idx, 1);
		}
		
	}
#if 1	
	// Create a reversed graph
	for(idx = 0; idx < VERTEX_CNT; idx++)
    {
      node_t *iterator = adjList[idx]->next;
	  printf("\r\n Vertex = %d", idx);
	  
	  while(iterator!=NULL)
	  {
		  printf("\r\n reverse = %d", iterator->v); 
		  insertIntoAdjacencyList(idx,adjListReversedGraph[iterator->v]);
		  iterator = iterator->next;
	  }
    }

	// Mark all the vertices as not visited (For second DFS)
	for(idx = 0; idx < VERTEX_CNT; idx++)
	{
	  visited[idx] = 0;
	}

	// Pop vertices from the stack
	for(idx = 0; idx < VERTEX_CNT; idx++)
	{
		int curVertex = stack_pop();
		
		if(visited[curVertex] == 0)
		{
			DFSUtil(curVertex,2);
			countSCC++;
			printf("\r\nSCC size = %d",scc_size);
			scc_size = 0;
		}
	}
#endif
	printf("\r\ncountSCC = %d\r\n",countSCC);
    return 0;
}