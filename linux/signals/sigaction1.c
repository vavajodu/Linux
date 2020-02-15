#include<stdio.h>
#include<signal.h>
void my_isr(int n)
{
	printf("In my_isr...\n");
	
}
main()
{
	if(fork()==0)
	{
		printf("In child...%d\n",getpid());
		while(1);
	}
	else
	{
	struct sigaction v;
	v.sa_handler=my_isr;
	sigemptyset(&v.sa_mask);
//	v.sa_flags=SA_NOCLDSTOP;			//it will go to my_isr only if child terminate
//	v.sa_flags=0;					//it will go to my_isr even if child is stopped using kill -19
	sigaction(17,&v,NULL);			
	printf("In main()...\n");
	while(1);
	}
}
