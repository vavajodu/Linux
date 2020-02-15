#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
main()
{
	int r,s;
	if(fork()==0)
	{
		printf("In child...%d\n",getpid());
		while(1);
//		sleep(10);
	}
	else
	{
		printf("In parent...\n");
		r=waitpid(-1,&s,WUNTRACED|WCONTINUED);
		s=s>>8;
		printf("After sleep r=%d s=%d\n",r,s);
	}
}
