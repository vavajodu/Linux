#include"header.h"
void main()
{
	int id;
	char *p;	
	id=shmget(5,50,IPC_CREAT|0644);
	if(id<0)
	{
		perror("shmget");
		return;
	}
	p=shmat(id,0,0);
	perror("shmat");
	printf("%s\n",p);
	shmdt(0);
}
