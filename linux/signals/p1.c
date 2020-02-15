#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
	if(fork()==0)
	{
		printf("In child.......%d\n",getpid());
		while(1);
	}
	else
	{
		int s;
		printf("In parent..\n");
		wait(&s);
		if(WIFEXITED(s))
			printf("child terminated normally with signal %d\n",WEXITSTATUS(s));
		else if(WIFSIGNALED(s))
			printf("child is terminated abnormally with %d signal\n",WTERMSIG(s));
		while(1);
	}
}
