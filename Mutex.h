/* Operation systems
 * exe #2
 * Or Halevga			201549805
 * Maria Tolstov		---------
 * This is the header file of Mutex.c file */

#ifndef _MUTEX_H_
#define _MUTEX_H_

/*define*/
#define MAX_THREADS 10
#define MAX_MUTEXES 10
#define LOCK 1
#define UNLOCK 0

typedef struct{	
	int is_lock; // locked = 1, unlocked = 0
	struct thread* waiting_threads_list[MAX_THREADS];	
} mutex;

/*Mutex operations*/
int mutex_init(mutex *m, int is_locked);
int mutex_lock(mutex *m);
int mutex_unlock(mutex *m);

#endif

