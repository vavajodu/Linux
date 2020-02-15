#include"header.h"
void main()
{
	int id;
	id=shmget(5,50,IPC_CREAT|0644);
	if(id<0)
	{
		perror("shmget");
		return;
	}
	printf("Id=%d\n",id);

}
