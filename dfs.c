#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

void swap(char *x, char *y)
{
  char temp = *x;
  *x = *y;
  *y = temp;
}

typedef struct node_t
{
	int val;
	struct node_t *next;
}node;

typedef struct queue_t
{
	node *head;
    node *tail;
    int queueSize;
}queue;

typedef struct graph_t{
    int V;
    int E;
    node **adjList; //pointer to a list of nodes pointing each to a set of vertices..
	int *visited; //pointer to array of visited vertices
}graph;

//Global pointers
graph *mygraph;
queue *myqueue;

int isEmpty(graph* t_graph)
{
	if(myqueue->head == NULL)
		return 1;
	return 0;
}

void addEdge(graph* t_graph, int src, int dest)
{
	node* srcNode = NULL;
	node* dstNode = NULL;
	node *prev = NULL;
	
    if(t_graph->adjList[src] == NULL)
	{
	   srcNode = malloc(sizeof(node));
       t_graph->adjList[src] = srcNode;
	   srcNode->val = src;
	   srcNode->next = NULL;
	}
	else
		srcNode = t_graph->adjList[src];

	dstNode = malloc(sizeof(node));

	//printf("\r\n src, dest = %d  %d", src,dest);

	dstNode->val = dest;
	dstNode->next = NULL;
    srcNode = prev = t_graph->adjList[src];
	
	while(srcNode != NULL)		
	{
	   prev = srcNode;
	   srcNode = srcNode->next;
	}
	
	prev->next = dstNode;	
	t_graph->E++;
	
}
// Queue is represented by linked list as 
// Insert at head and remove from tail

// a-> b- > c -> d -> NULL/
// a is the oldest node..which is the head
// d is the latest node which is the tail
void createGraph(int vertexCount)
{
	int i = 0;
	mygraph = malloc(sizeof(graph));
	mygraph->V = vertexCount;
	mygraph->E = 0;	
    
	mygraph->adjList = malloc(mygraph->V * sizeof(node *));
    mygraph->visited  = malloc(mygraph->V * sizeof(int));

    for (i = 0; i < mygraph->V; i++) 
	{
        mygraph->adjList[i] = NULL;
		mygraph->visited[i] = 0;
    }
}

// insert and update tail
void insert(int data)
{
  node *ptr = malloc(sizeof(node));
  ptr->val = data;
  ptr->next = NULL;
  myqueue->queueSize++;
  if((myqueue->head == NULL) && (myqueue->tail == NULL))
  {
	  myqueue->head = myqueue->tail = ptr;
	  printf("Add to empty queue!\r\n");
  }
  else if(myqueue->tail!=NULL)
  {
	  myqueue->tail->next = ptr;
	  myqueue->tail = ptr;
	  //printf("...Add to tail\r\n");
	  if(myqueue->head == NULL)
		  myqueue->head = myqueue->tail;
  }
  else
	  printf("\r\nError!!!");
}

// remove from head
int delete()
{
   int data = 0;
   /*
   if(myqueue->head == NULL)
	   printf("Delete() found a null in head\r\n");
   else
	   printf("Delete()\r\n");
   */
   node *ptr = myqueue->head;
   data = ptr->val;
   myqueue->head = ptr->next;
   free(ptr);
   myqueue->queueSize--;
   return data;
}

void dfs(graph *graphPtr, int vertex)
{
	node *temp = graphPtr->adjList[vertex];
	if(temp == NULL)
		return;
	graphPtr->visited[vertex] = 1;
	
	printf("\r\nVisited = %d", vertex);
    temp = graphPtr->adjList[vertex]->next;

	while(temp)
	{	   
	   if(graphPtr->visited[temp->val] == 0) //if not visited..
	   {
		  //graphPtr->visited[adjVertex] = 1;
		  dfs(graphPtr, temp->val);
	   }
	   temp = temp->next;
	}
}

void bfs(graph *graphPtr, int vertex)
{
	myqueue = malloc(sizeof(queue));
	myqueue->head = myqueue->tail = NULL;
	graphPtr->visited[vertex] = 1;
	
	insert(vertex);
	
	while(!isEmpty(graphPtr))
	{
		int element = delete();
	    
		if(graphPtr->visited[element])
		{
		  printf("Visited = %d\r\n",element);
		}
		
		node *temp = graphPtr->adjList[element];
		
		while(temp)
		{
			int adjVertex = temp->val;
			//printf("\r\nadjVertex = %d", adjVertex);
			if(graphPtr->visited[adjVertex] == 0)
			{
				graphPtr->visited[adjVertex] = 1;
			    insert(adjVertex);
			}

			temp = temp->next;			
		}
	}
}

int main()
{
  int i,j;
  createGraph(4); //Using global mygraph
  printf("nodecount = %d ", mygraph->V);
#if 0
  addEdge(mygraph,0,1);
  addEdge(mygraph,0,2);
  addEdge(mygraph,1,3);
  addEdge(mygraph,1,4);
  addEdge(mygraph,2,5);
  addEdge(mygraph,2,6);
#else
  addEdge(mygraph,0, 1);
  addEdge(mygraph,0, 2);
  addEdge(mygraph,1, 2);
  addEdge(mygraph,2, 0);
  addEdge(mygraph,2, 3);
  addEdge(mygraph,3, 3);
#endif	
  printf("\r\n");
#if 1
  for(i=0; i< mygraph->V;  i++)
  {
	  printf("\r\nnode = ");
	  node *ptr  = mygraph->adjList[i];
	  if(!ptr)
		  printf("%d has no leaves\r\n", i);
	  else
	  {
		  while(ptr)
		  {
			  printf(" %d ", ptr->val); 
			  ptr = ptr->next;
		  }
	  }
  }
#endif
  //bfs(mygraph,0);
//  dfs(mygraph,0);
dfs(mygraph,2);
  return 0;
}