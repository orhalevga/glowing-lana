/* Operation systems
 * exe #2
 * Or Halevga			201549805
 * Maria Tolstov		---------
 * This is the header file of Thread.c file 
 * Assumptions:
 * round_robin base scheduling 
 * quantom of 1 sec
 * all threads have same priority*/

#ifndef _THREAD_H_
#define _THREAD_H_

/*define stack size*/
#define ESP_OFFSET 4096

/*define thread status*/
#define CREATED 2
#define	READY	1
#define RUNNING	0
#define SLEEP	-1
#define ZOMBIE	-2

/*Thread struct*/
typedef struct{	
	int id;
	void* stack;
	void* func;
	void* ret_val;
	int state;
} thread;

/*Thread operations*/
int thread_create(thread_t *thread_id, void *(*start_routine)(void *), void *arg);
void thread_exit(void *return_value);
int thread_join(int thread_id, void **return_value_ptr);
void thread_return();
/*Sheduler*/
void sheduler (int signal_num);
#endif
