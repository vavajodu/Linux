#include"header.h"
void main()
{
	int p[2];
	pipe(p);
	if(fork()==0)
	{//child
		close(0);		//closing STD_IN
		dup(p[0]);		//read end will get fd 0 so read from pipe read end not key board
		execlp("grep","grep","pts/2",NULL);
	}
	else
	{//parent
		close(1);			//closing STD_OUT
		dup(p[1]);			//duplecating write end so output will go in pipe not on screen
		execlp("ps","ps","-el",NULL);
	}
}		
