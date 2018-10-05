#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>

// Expected answer is Vertex   Distance from Source
// 2599,2610,2947,2052,2367,2399,2029,2442,2505,3068,
#define VERTEX_CNT 200
#define INT_MAX 1000000
#define VISITED 1
#define NOT_VISITED 0

unsigned int graph[VERTEX_CNT][VERTEX_CNT];
unsigned int distance[VERTEX_CNT];
unsigned char visited[VERTEX_CNT]; //forms the shortest path

///void dijkstra(unsigned int graph[V][V], int src);
unsigned int arrayIndex[10]={7,37,59,82,99,115,133,165,188,197};

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree  
unsigned int findMinVertex()
{
	unsigned int minVertex = 0;//0xFF;
	unsigned int minDistance  = INT_MAX;
	unsigned int idx  = 0;
	
	for(idx = 0; idx < VERTEX_CNT; idx++)
	{
		if(visited[idx] == NOT_VISITED) //Not yet visited..
		{
			if(distance[idx] <= minDistance)
			{
				minVertex = idx;
				minDistance = distance[idx];
			}
		}
	}
	//printf("minVertex = %d, dist = %d \r\n", minVertex, minDistance);
	return minVertex;
}

void dijkstra()
{
   int i;
   int j;
   
   for(i=0;i<VERTEX_CNT;i++)
   {
	   distance[i] = INT_MAX;
	   visited[i]  = NOT_VISITED;
   }
   
   distance[0] = 0; //distance from itself is 0 for node 0
   
   for(i=0;i<VERTEX_CNT-1;i++)
   {
       /// Find minimum Distance from unvisited nodes.
	   unsigned int minVertex = findMinVertex();
	   
	   // Set this node to visited..
	   visited[minVertex] = VISITED;

	   // Now check adjacency matrix for all neighbours of minVertex..edge is [minVertex][j]
	   for(j=0;j<VERTEX_CNT;j++)
	   {
		   // if edge exists from minVertex to j and j is not VISITED yet..
		   if((graph[minVertex][j] !=0) && (visited[j] != VISITED))
		   {
			   // Get distance from minVertex to j by
			   // Sum of = Source to minVertex distance distance[minVertex] + minVertex to j
			   unsigned int cur_dist = distance[minVertex] +graph[minVertex][j];

			   // if distance from source to minVertex is not infinity...
			   // And if cur distance is less than the above value..
			   if((distance[minVertex] !=INT_MAX) && (cur_dist <= distance[j]))
			   {
				   distance[j] = cur_dist;
			   }
		   }
	   }
   }
   printf("Vertex Distance from Source\n");

   j = 0;

   for(i=0; i<VERTEX_CNT; i++)
   {
	  if((arrayIndex[j]-1) == i)
	  {
		  //printf("%d ",arrayIndex[j]);
		  printf("%d,", distance[i]);
		  j++;
	  }
   }
}

int main(void)
{
    unsigned int v1,v2,v3;
	char c;
	
	unsigned long countEdges = 0;
    unsigned long idx  = 1;
	unsigned long jdx  = 0;

    FILE *fp;

    if((fp = fopen("C:\\Users\\smandke\\Documents\\dijkstraData.txt", "r+")) == NULL) {
//	  if((fp = fopen("C:\\Users\\smandke\\Documents\\djikstrad.txt", "r+")) == NULL) {
        printf("No such file\n");
        return 1;
    }
    
    while (v1 !=EOF) 
	{
        int ret = fscanf(fp, "%u", &v1);
		
        if(ret == 1)
		{
			//printf(" %d ",v1); //pick up the second vertex (to-vertex)

			while(true) // Found vertex array location
			{
				
				ret = fscanf(fp, "%u", &v2);
				if(ret == 1)
				{
				//	printf("(%d ,",v2);
				}
				else
					break;
				
				c = fgetc(fp);
				
				if(c == 9)
				{
				   if(v2 == (v1 + 1))
				   {
					   v1 = v2;
					   fscanf(fp, "%u", &v2);
					   
					   c = fgetc(fp);
					   
					   if((c!=',') || (c == EOF) || (c == '\n'))
					   {
						   break;
					   }
				   }
				   
				}
				else if((c!=',') || (c == EOF) || (c == '\n'))
				{
				 // printf("\r\nbreak 2 = %d\r\n",c);
				  break;
				}
					
				ret = fscanf(fp, "%u", &v3); //pick up the distance length

				if(ret == 1)
				{
				  //printf(" %d) ",v3);
				}
				else
				{
					//printf("\r\nbreak 3 = %d\r\n",c);
					break;
				}

                graph[v1-1][v2-1] = v3;
				//printf("%d ", graph[v1-1][v2-1]);
			}			
		 printf("\r\n");
		}
		
		break;
    }
#if 0
    dijkstra();
#else	
	// Start looking into the Graph...
	dijkstra(graph,0);
#endif
	return 0;
}
