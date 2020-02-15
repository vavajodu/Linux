#include<stdio.h>
#include<unistd.h>
#include<signal.h>
static int i;
void my_isr(int n)
{
	printf("In isr...\n");
	i--;
	if(i==0)
		raise(9);
	else
	{
		printf("%d\n",i);
		alarm(i);
	}
}
main(int argc,char **argv)
{
	i=atoi(argv[1]);
	alarm(i);
	signal(14,my_isr);
	while(1);
}
