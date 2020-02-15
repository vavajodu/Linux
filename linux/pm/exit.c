#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
main()
{
	if(fork()==0)
	{
		printf("in child...\n");
		while(1);
	}
	else
	{
		int r,s;
		printf("in pRENT..\n");
		r=wait(&s);
		if(WIFEXITED(s))
		{
			printf("child is normally exited %d\n",WEXITSTATUS(s));
		}
		else if(WIFSIGNALED(s))
		{
			printf("child is exir=ted by signal %d\n",WTERMSIG(s));
		}
	}
}
		
