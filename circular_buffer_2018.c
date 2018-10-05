#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define QUEUESIZE 10

typedef struct queue_t{
    int buf[QUEUESIZE];
	int head;
	int tail;
	int full;
    int	empty;
} queue;

queue *queueInit (void)
{
	queue *q;
    int i  =0;
	int j  = 0;
	q = (queue *)malloc (sizeof (queue));
	if (q == NULL) return (NULL);

	q->empty = 1;
	q->full = 0;
	q->head = 0;
	q->tail = 0;
	printf("0x%p\r\n",&q->head);
	printf("0x%p\r\n",&q->tail);
	//memset(q->buf, 0, QUEUESIZE); //does not zero out the values..
	for(i=0; i < QUEUESIZE; i++)
	{		
        q->buf[j] = 0;
		printf("j = %d  : %d or %x or %d \r\n",j,q->buf[j], q->buf[i], dummyBuf[i]);
		j = (j+1)%QUEUESIZE;
	}
	printf("\r\n");
	return q;
}


void queueAdd (queue *q, int in)
{
	printf("queue adding %d\r\n",in);
	if(q->full ==1)
	{
    	printf("queue full\n");
		return;
	}
		
  
	q->buf[q->tail] = in;
	q->tail++;
	if (q->tail == QUEUESIZE)
		q->tail = 0;
	if (q->tail == q->head)
		q->full = 1;
	q->empty = 0;

	return;
}

void queueDel (queue *q, int *out)
{
	*out = q->buf[q->head];

	q->head++;
	if (q->head == QUEUESIZE)
		q->head = 0;
	if (q->head == q->tail)
		q->empty = 1;
	q->full = 0;

	return;
}

int getQueueElemCount(queue *q)
{
	if(q->tail > q->head)
	{
		return (q->tail - q->head + 1);
	}
	
	return (QUEUESIZE - (q->head - q->tail));
}

void printQ(queue *q)
{
	int i = 0;
	int j = q->head;
	int elemCount = 0;
	printf("\r\nprintQ for head, tail = %d %d count = %d\r\n",q->head, q->tail,getQueueElemCount(q));
	for(i=0; i < getQueueElemCount(q); i++)
	{		
		printf("%d ",q->buf[j]);
		j = (j+1)%QUEUESIZE;
		
		if(j==q->tail)
			break;

	}
	printf("\n\n");
}
int main()
{
	int i = 0;
	int retVal = 0;
	queue *q = queueInit();
	//printQ(q);
	for(i=0; i < 12; i++)
	{
		queueAdd(q,i+1);
	}
			printQ(q);
	queueDel(q, &retVal);
			printf("\r\ndeleted retVal = %d\r\n",retVal);printQ(q); 
	queueDel(q, &retVal);
			printf("\r\ndeleted retVal = %d\r\n",retVal);printQ(q); 
	queueDel(q, &retVal);
			printf("\r\ndeleted retVal = %d\r\n",retVal);printQ(q); 
	queueAdd(q,11);
			printQ(q);
	queueAdd(q,12);
			printQ(q);
	queueAdd(q,13);
			printQ(q);
	
	return 0;
}
