#include<stdio.h>
#include<sys/types.h>
#include<sys/resource.h>
void my_isr(int n)
{
	printf("in my_isr...\n");
}
main()
{
	struct rlimit v;
	getrlimit(RLIMIT_DATA,&v);
	printf("Soft limit=%u Hard limit=%u\n",v.rlim_cur,v.rlim_max);
	v.rlim_cur=20;
	setrlimit(RLIMIT_DATA,&v);
	getrlimit(RLIMIT_DATA,&v);
	printf("Soft limit=%u Hard limit=%u\n",v.rlim_cur,v.rlim_max);
	printf("in main...%d\n",getpid());
	perror("getrlimit");
	while(1);
}
