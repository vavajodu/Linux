#include<stdio.h>
#include<unistd.h>
#include<signal.h>
void my_isr(int n)
{
	printf("In mt_isr\n");
	raise(9);
}
main()
{
	printf("Hello\n");
	alarm(10);
	signal(14,my_isr);
	while(1);
}
