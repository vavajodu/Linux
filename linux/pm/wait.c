#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
main()
{
	int s;
	if(fork()==0)
	{
		printf("In child...\n");
//		sleep(10);
	}
	else
	{
		printf("In parent..\n");
		wait(&s);
		if(WIFEXITED(s))
		{
			printf("Normally terminated...%d\n",WEXITSTATUS(s));
		}
		else if (WIFSIGNALED(s))
		{
			printf("Abnormally...%d\n",WTERMSIG(s));
		}
	}
}
