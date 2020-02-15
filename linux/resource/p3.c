#include<stdio.h>
#include<sys/types.h>
#include<sys/resource.h>
void my_isr(int n)
{
	printf("In my_isr...\n");
}
main()
{
	FILE *fp;
	struct rlimit v;
	getrlimit(RLIMIT_FSIZE,&v);
	printf("Soft limit=%u Hard limit=%u\n",v.rlim_cur,v.rlim_max);
	v.rlim_cur=5;
	setrlimit(RLIMIT_FSIZE,&v);
	getrlimit(RLIMIT_FSIZE,&v);
	printf("Soft limit=%u Hard limit=%u\n",v.rlim_cur,v.rlim_max);
	fp=fopen("data","r");
	signal(25,my_isr);
		while(1);
}
