/* Operation systems
 * exe #2
 * Or Halevga			201549805
 * Maria Tolstov		---------  
 * This is Threads.c file*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h> 
#include "Thread.h" 
#include "Mutex.h" 

//save current thread 
static int curr_thread;

//number of living threads -1 for main
//static int threads_num = 1; 

//list of threads
static struct thread thread_list[MAX_THREADS];

/*Thread operations*/
int thread_create(thread_t *thread_id, void *(*start_routine)(void *), void *arg){
	
	/* find place in array
	 * initalize data structure with parameters.
	 * go back to scheduler
	 * 
	 */
	
	return 0;
}
void thread_exit(void *return_value){
	/*int idx;
	
	alarm(0); -switch off alarm for avoiding deadlock
	thread_list[curr_thread].ret_val = return_value; - saving ret val
	thread_list[curr_thread].state = ZOMBIE; - change state
	
	for (idx=0 ; idx < MAX_THREADS : idx++) - change the threads that waiting for me to ready
	{
		if (threads[idx].state == SLEEP &&
			(is threads[idx] on waiting list) == current_thread)
			{
				threads[idx].state = READY;
				threads[idx] out of waiting_list
			}
	}
	raise(SIGALARM);*/
}
int 
thread_join(int tid, void **return_value_ptr){
	/*
	if (tid < 0 || tid >= threads_num || tid == curr_thread)
		return -1;
		
		alarm(0); //entering critical segment;
		if(threads_list[tid].state != ZOMBIE)
		{
			threads_list[curr_thread].wating_for = tid;
			threads_list[curr_thread].state = SLEEP;
		}
		raise(SIGALARM);
		if (result != NULL)
			*result = threads_list[tid].retval;
		return 0;*/
}
void thread_return()
{
	//push eax - return value always will be at eax register
	//call thread_exit
}

/* Scheduler */
void scheduler (int signal_num){
	/* save current thread state - we dont need to do it becuse it saved automaticlly by the OS
	 * choose thread to run
	 * restoring the state of the thread we choose to run - we dont need to do it becuse it restored by the OS*/
}
