#include<stdio.h>
#include<sys/resource.h>
#include<sys/types.h>
void my_isr(int n)
{
	printf("In my_isr..\n");
	raise(9);
}
main()
{
	struct rlimit v;
	getrlimit(RLIMIT_CPU,&v);
	printf("Soft limit=%u hard limit=%u\n",v.rlim_cur,v.rlim_max);
	printf("In main...%d\n",getpid());
	v.rlim_cur=10;
	setrlimit(RLIMIT_CPU,&v);
	getrlimit(RLIMIT_CPU,&v);
	printf("Soft limit=%u hard limit=%u\n",v.rlim_cur,v.rlim_max);
	signal(24,my_isr);	
	while(1);
}
