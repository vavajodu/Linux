#include<stdio.h>
#include<signal.h>
void my_isr(int n)
{
	printf("In my_isr...\n");
}
main()
{
	struct sigaction v;
	if(fork()==0)
	{
		printf("In child...%d\n",getpid());
		sleep(10);
	}
	else
	{
		v.sa_handler=my_isr;				//filling structure variable
		sigemptyset(&v.sa_mask);			//           "
		v.sa_flags=SA_NOCLDWAIT;			//	     "
		printf("In parent..\n");
		sigaction(SIGCHLD,&v,NULL);			//it will work as wait,
		printf("After terminating child..\n");
		while(1);
	}
}
