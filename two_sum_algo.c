#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>

#define NUM_CNT 1000000

int array[NUM_CNT+1];

int main()
{
  	FILE *fp;
    int v1;
	int idx = 0;
	int jdx = 0;
	int countPair = 0;
	
    if((fp = fopen("C:\\Users\\smandke\\Documents\\algo1-programming_prob-2sum.txt", "r+")) == NULL) {
        printf("No such file\n");
        return 1;
    }
    
	while (true) 
	{
        int ret = fscanf(fp, "%u", &v1);
		
		if(ret == EOF) 
		{
            break;
		}

		array[idx] = v1;
		idx++;		
		
		if(idx==NUM_CNT)
			break;
	}
	
	for(idx = -10000; idx <= 10000; idx++)
	{
		for(jdx = 0; jdx <  NUM_CNT ; jdx++)
		{
			if(HashMap[idx - HashMap[jdx]] == 0)
			{
			   countPair++;
			}
		}
	}
	
	printf("Number of pairs for [-10000, 10000] are %d\r\n", countPair);

  return 0;
}