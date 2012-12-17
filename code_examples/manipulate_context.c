// Needed to get the constants for the regs indices in sys/ucontext.h
#define _GNU_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <ucontext.h>

void f(int x) {
	printf("Exiting through f() - x is %d\n", x);
	exit(0);
}

void g() {
	__asm__ __volatile__ (
			"push $3\n\t"
			"call f");
}

void handler(int signum, siginfo_t* info, void *old_context) {

	ucontext_t *ctx;

	printf("Saved context is at %p\n", old_context);

	ctx = (ucontext_t *)old_context;
	ctx->uc_mcontext.gregs[REG_EIP] = (int)g;

	// When leaving the handler, the restored context will take us to g()
}

void *get_esp() {
	__asm__ __volatile__ ("mov %esp,%eax");
}

int main() {
	struct sigaction sa;

	printf("ESP = %p\n", get_esp());

	sa.sa_sigaction = handler;
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGALRM, &sa, NULL) == -1) {
		perror("Error installing signal handler");
		exit(-1);
	}
	//raise(SIGALRM);
	alarm(3);
	alarm(0);
	sleep(4);	
	printf("Exiting through main\n");
	return 0;
}
