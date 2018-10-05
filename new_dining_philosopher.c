/* Includes */
#include <unistd.h>     /* Symbolic Constants */
#include <sys/types.h>  /* Primitive System Data Types */ 
#include <errno.h>      /* Errors */
#include <stdio.h>      /* Input/Output */
#include <stdlib.h>     /* General Utilities */
#include <pthread.h>    /* POSIX Threads */
#include <string.h>     /* String handling */
#include <semaphore.h>  /* Semaphore */

 
#define N 5
#define THINKING 2
#define HUNGRY 1
#define EATING 0
#define LEFT (phnum + 4) % N
#define RIGHT (phnum + 1) % N
 
int state[N] = {THINKING, THINKING, THINKING, THINKING, THINKING};
int phil[N] = { 0, 1, 2, 3, 4 };
 

/* global mutex for our program. assignment initializes it */
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
sem_t S[N];
 
void test(int phnum)
{
    if (state[phnum] == HUNGRY
        && state[LEFT] != EATING
        && state[RIGHT] != EATING) {
        // state that eating
        state[phnum] = EATING;
 
        sleep(2);
 
        printf("Philosopher %d takes fork %d and %d\n",
                      phnum + 1, LEFT + 1, phnum + 1);
 
        printf("Philosopher %d is EATING\n", phnum + 1);
 
        // sem_post(&S[phnum]) has no effect
        // during takefork
        // used to wake up hungry philosophers
        // during putfork
        sem_post(&S[phnum]);
    }
	else
	{
		printf("Philosopher %d is HUNGRY but not EATING because ", phnum + 1);
		
		if(state[LEFT] == EATING)
		{
			printf("state[%d] = EATING ", LEFT);
		}
		else if(state[LEFT] == THINKING)
			printf("state[%d] = THINKING ", LEFT);
		else if(state[LEFT] == HUNGRY)
			printf("state[%d] = HUNGRY ", LEFT);
		
		
        if(state[RIGHT] == EATING)
		{
			printf("state[%d] = EATING ", RIGHT);
		}
		else if(state[RIGHT] == THINKING)
			printf("state[%d] = THINKING ", RIGHT);
		else if(state[RIGHT] == HUNGRY)
			printf("state[%d] = HUNGRY ", RIGHT);
		
		printf("\r\n");
	}
}
 
// take up chopsticks
void take_fork(int phnum)
{
    int retVal = pthread_mutex_lock(&mutex);
 
    if(retVal == 0)
		printf(" lock acquired for Philosopher %d\r\n\r\n", 1+phnum);
	
    // state that hungry
    state[phnum] = HUNGRY;
 
    printf("Philosopher %d is HUNGRY\n", 1+phnum);
 
    // eat if neighbours are not eating
    test(phnum);
    
	if(state[phnum] !=EATING)
	{
		retVal = pthread_mutex_unlock(&mutex);
    	// if unable to eat wait to be signalled
        sem_wait(&S[phnum]);
		retVal = pthread_mutex_lock(&mutex);
	}			

    retVal = pthread_mutex_unlock(&mutex);
 
    if(retVal == 0)
		printf(" unlock done for Philosopher %d\r\n",1+phnum);
	
	// if unable to eat wait to be signalled
    //sem_wait(&S[phnum]);
 
    sleep(1);
}
 
// put down chopsticks
void put_fork(int phnum)
{
 
    int retVal = pthread_mutex_lock(&mutex);
 
    if(retVal == 0)
		printf(" lock acquired for Philosopher %d\r\n\r\n",1+phnum);

    // state that thinking
    state[phnum] = THINKING;
 
    printf("Philosopher %d putting fork %d and %d down\n",
           phnum + 1, LEFT + 1, phnum + 1);
    printf("Philosopher %d is THINKING\n", 1+phnum);
 
    test(LEFT);
    test(RIGHT);
 
    retVal = pthread_mutex_unlock(&mutex);
 
    if(retVal == 0)
		printf(" unlock done for Philosopher %d\r\n\r\n",1+phnum);
}
 
void* philospher(void* num)
{
 
    while (1) {
 
        int* i = num;
 
        sleep(1);
 
        take_fork(*i);
 
        sleep(0);
 
        put_fork(*i);
    }
}
 
int main()
{
 
    int i;
    pthread_t thread_id[N];
 

    for (i = 0; i < N; i++)
 
        sem_init(&S[i], 0, 0);
 
    for (i = 0; i < N; i++) {
 
        // create philosopher processes
        pthread_create(&thread_id[i], NULL,
                       philospher, &phil[i]);
 
        printf("Philosopher %d is THINKING\n", i + 1);
    }
 
    for (i = 0; i < N; i++)
 
        pthread_join(thread_id[i], NULL);
}