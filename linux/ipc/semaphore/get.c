#include"header.h"
void main(int argc,char **argv)
{
	if(argc!=2)
	{
		printf("Usage:./get id\n");
		return;
	}
	int id,ret;
	id=semget(5,5,IPC_CREAT|0644);
	if(id<0)
	{
		perror("semget");
		return;
	}
	printf("id=%d\n",id);
	ret=semctl(id,atoi(argv[1]),GETVAL);
	printf("Ret=%d\n",ret);
}
