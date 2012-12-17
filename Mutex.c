/* Operation systems
 * exe #2
 * Or Halevga			201549805
 * Maria Tolstov		---------  
 * This is Mutex.c file*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h> 
#include "Thread.h" 
#include "Mutex.h" 

//MAX_MUTEXES maximum mutexes in program 
static struct mutex mutex_list[MAX_MUTEXES];

int mutex_init(mutex *m, int is_locked){
	m.is_lock = is_locked;
	//m.waiting_list = NULL;
}
int mutex_lock(thread_mutex_t mutex){
	m.is_lock = LOCK;
}
int mutex_unlock(thread_mutex_t mutex){
	m.is_lock = UNLOCK;
}

