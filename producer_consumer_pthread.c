/*
 *	File	: pc.c
 *
 *	Title	: Demo Producer/Consumer.
 *
 *	Short	: A solution to the producer consumer problem using
 *		pthreads.	
 *
 *	Long 	:
 *
 *	Author	: Andrae Muys
 *
 *	Date	: 18 September 1997
 *
 *	Revised	:
 */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
/*
The pthread_cond_timedwait() and pthread_cond_wait() functions shall block on a condition variable. 
The application shall ensure that these functions are called with mutex locked by the calling thread; otherwise, an error  or undefined behavior (for other mutexes) results.
These functions atomically release mutex and cause the calling thread to block on the condition variable cond; 
atomically here means "atomically with respect to access by another thread to the mutex and then the condition variable". 
That is, if another thread is able to acquire the mutex after the about-to-block thread has released it, 
then a subsequent call to pthread_cond_broadcast() or pthread_cond_signal() in that thread shall behave as if it were issued after 
the about-to-block thread has blocked.
Upon successful return, the mutex shall have been locked and shall be owned by the calling thread. If mutex is a robust mutex where an owner terminated while holding the lock and the state is recoverable, the mutex shall be acquired even though the function returns an error code.
  */
#define QUEUESIZE 10
#define LOOP 20

void *producer (void *args);
void *consumer (void *args);

typedef struct {
	int buf[QUEUESIZE];
	long head, tail;
	int full, empty;
	pthread_mutex_t *mut;
	pthread_cond_t *notFull, *notEmpty;
} queue;

queue *queueInit (void);
void queueDelete (queue *q);
void queueAdd (queue *q, int in);
void queueDel (queue *q, int *out);

int main ()
{
	queue *fifo;
	pthread_t pro, con;

	fifo = queueInit ();
	if (fifo ==  NULL) {
		fprintf (stderr, "main: Queue Init failed.\n");
		exit (1);
	}
	
	/***
	for(thread_id = 0; thread_id < PRODUCER_COUNT; thread_id++)
    {
        data[thread_id] = thread_id;
        pthread_create(&threads[thread_id], NULL, producer, &data[thread_id]);
    }
	 ***/
	pthread_create (&pro, NULL, producer, fifo);
	pthread_create (&con, NULL, consumer, fifo);
	pthread_join (pro, NULL);
	pthread_join (con, NULL);
	queueDelete (fifo);

	return 0;
}

void *producer (void *q)
{
	queue *fifo;
	int i;

	fifo = (queue *)q;

	for (i = 0; i < LOOP; i++) {
		pthread_mutex_lock (fifo->mut);
		while (fifo->full) {
			printf ("producer: queue FULL.\n");
			pthread_cond_wait (fifo->notFull, fifo->mut);
		}
		queueAdd (fifo, i);
		pthread_mutex_unlock (fifo->mut);
		pthread_cond_signal (fifo->notEmpty);
		usleep (100000);
	}
	for (i = 0; i < LOOP; i++) {
		pthread_mutex_lock (fifo->mut);
		while (fifo->full) {
			printf ("producer: queue FULL.\n");
			pthread_cond_wait (fifo->notFull, fifo->mut);
		}
		queueAdd (fifo, i);
		pthread_mutex_unlock (fifo->mut);
		pthread_cond_signal (fifo->notEmpty);
		usleep (200000);
	}
	return (NULL);
}

void *consumer (void *q)
{
	queue *fifo;
	int i, d;

	fifo = (queue *)q;

	for (i = 0; i < LOOP; i++) {
		pthread_mutex_lock (fifo->mut);
		while (fifo->empty) {
			printf ("consumer: queue EMPTY.\n");
			pthread_cond_wait (fifo->notEmpty, fifo->mut);
		}
		queueDel (fifo, &d);
		pthread_mutex_unlock (fifo->mut);
		pthread_cond_signal (fifo->notFull);
		printf ("consumer: recieved %d.\n", d);
		usleep(200000);
	}
	for (i = 0; i < LOOP; i++) {
		pthread_mutex_lock (fifo->mut);
		while (fifo->empty) {
			printf ("consumer: queue EMPTY.\n");
			pthread_cond_wait (fifo->notEmpty, fifo->mut);
		}
		queueDel (fifo, &d);
		pthread_mutex_unlock (fifo->mut);
		pthread_cond_signal (fifo->notFull);
		printf ("consumer: recieved %d.\n", d);
		usleep (50000);
	}
	return (NULL);
}

#ifdef 0
typedef struct {
	int buf[QUEUESIZE];
	long head, tail;
	int full, empty;
	pthread_mutex_t *mut;
	pthread_cond_t *notFull, *notEmpty;
} queue;
#endif

queue *queueInit (void)
{
	queue *q;

	q = (queue *)malloc (sizeof (queue));
	if (q == NULL) return (NULL);

	q->empty = 1;
	q->full = 0;
	q->head = 0;
	q->tail = 0;
	q->mut = (pthread_mutex_t *) malloc (sizeof (pthread_mutex_t));
	pthread_mutex_init (q->mut, NULL);
	q->notFull = (pthread_cond_t *) malloc (sizeof (pthread_cond_t));
	pthread_cond_init (q->notFull, NULL);
	q->notEmpty = (pthread_cond_t *) malloc (sizeof (pthread_cond_t));
	pthread_cond_init (q->notEmpty, NULL);
	
	return (q);
}

void queueDelete (queue *q)
{
	pthread_mutex_destroy (q->mut);
	free (q->mut);	
	pthread_cond_destroy (q->notFull);
	free (q->notFull);
	pthread_cond_destroy (q->notEmpty);
	free (q->notEmpty);
	free (q);
}

void queueAdd (queue *q, int in)
{
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