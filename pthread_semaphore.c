/* Includes */
#include <unistd.h>     /* Symbolic Constants */
#include <sys/types.h>  /* Primitive System Data Types */ 
#include <errno.h>      /* Errors */
#include <stdio.h>      /* Input/Output */
#include <stdlib.h>     /* General Utilities */
#include <pthread.h>    /* POSIX Threads */
#include <string.h>     /* String handling */
#include <semaphore.h>  /* Semaphore */

/* global mutex for our program. assignment initializes it */
pthread_mutex_t a_mutex = PTHREAD_MUTEX_INITIALIZER;

/* prototype for thread routine */
void handler ( void *ptr );

/* global vars */
/* semaphores are declared global so they can be accessed 
   in main() and in thread routine,
   here, the semaphore is used as a mutex */

int counter; /* shared variable */

int main()
{
    int i[2];
    pthread_t thread_a;
    pthread_t thread_b;
    
    i[0] = 0; /* argument to threads */
    i[1] = 1;
    
                                 
    /* Note: you can check if thread has been successfully created by checking return value of
       pthread_create */                                 
    pthread_create (&thread_a, NULL, (void *) &handler, (void *) &i[0]);
    pthread_create (&thread_b, NULL, (void *) &handler, (void *) &i[1]);
    
    pthread_join(thread_a, NULL);
    pthread_join(thread_b, NULL);
         
    /* exit */  
    exit(0);
} /* main() */

void handler ( void *ptr )
{
    int x; 
    x = *((int *) ptr);
    printf("Thread %d: Waiting to enter critical region...\n", x);
    int retVal = pthread_mutex_lock(&a_mutex);
	
	if(retVal == 0)
	{
		printf("  Locked Mutex.....\r\n");
	}
    /* START CRITICAL REGION */
    printf("Thread %d: Now in critical region...\n", x);
    printf("Thread %d: Counter Value: %d\n", x, counter);
    printf("Thread %d: Incrementing Counter...\n", x);
    counter++;
    printf("Thread %d: New Counter Value: %d\n", x, counter);
    printf("Thread %d: Exiting critical region...\n", x);
    /* END CRITICAL REGION */    
    retVal = pthread_mutex_unlock(&a_mutex);
	
	if(retVal == 0)
	{
		printf("   unLocked Mutex.....\r\n");
	}
    
    pthread_exit(0); /* exit thread */
}