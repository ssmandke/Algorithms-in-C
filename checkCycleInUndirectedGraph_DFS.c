typedef struct node_t
{
  struct node_t *next;
  char data;
}node;

typedef struct graph_t
{
  char E;
  char V;
  node **adjList;
  char *visited;
}graph;

graph* createGraph(char v, char e)
{ 
  int i = 0;
  graph *newgraph = malloc(sizeof(graph));
  newgraph->E = e;
  newgraph->V = v;
  
  newgraph->adjList = malloc(sizeof(node *) * V);
  newgraph->visited = malloc(sizeof(char)   * E);

  for(i=0; i<v; i++)
  {
    newgraph->adjList[i] = malloc(sizeof(node));
    newgraph->adjList[i]->next = NULL;
  }

  return newgraph;
}

void addEdge(char u, char v, graph *graphPtr)
{
   node *ptr1 = graphPtr->adjList[u];
   node *ptr2 = graphPtr->adjList[v];
   
   while(ptr1->next)
   {
     ptr1 = ptr1->next;
   }

   ptr1->next = malloc(sizeof(node));
   ptr1->next->data = v;  

   while(ptr2->next)
   {
     ptr2 = ptr2->next;
   }

   ptr2->next = malloc(sizeof(node));
   ptr2->next->data = u;  

}

void dfs(graph *graphPtr, char vertex)
{
   graphPtr->visited[vertex] = true;
   node *ptr  = graphPtr->adjList[vertex];
      
   while(ptr)
   {
     if(graphPtr->visited[i] == false)
     {
       dfs(graphPtr, i);
     }

     ptr = ptr->next;
   }
}

bool isCyclic(graph *graphPtr)
{
  int i = 0;
  
  for(i=0; i<graphPtr->V; i++)
  {
    if(graphPtr->visited[i] == false)
    { 
       if(isCyclicUtil(graphPtr, i, -1) == true)
       {
          return true;
       }
    }
  }
  return false;
}

bool isCyclicUtil(graph* graphPtr, char vertex, char parent)
{
 
  graphPtr->visited[vertex] = true;
  node *ptr = graphPtr->AdjList[vertex];

  while(ptr)
  {
    if(graphPtr->visited[vertex] == false)
    {
       if(isCyclicUtil(graphPtr, ptr->data, vertex) == true)
       {
           return true;
       } 
       else
       {
           if(ptr->data != parent)
           { 
              return true;
           }
       }
    }
    ptr = ptr->next;
  }
 
}