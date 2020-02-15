#include"header.h"
void main()
{
	int id,ret,i;
	id=semget(5,5,IPC_CREAT|0644);
	if(id<0)
	{
		perror("semget");
		return;
	}
	printf("id=%d\n",id);
	printf("Before :------------\n");
	for(i=0;i<5;i++)
	{
		ret=semctl(id,i,GETVAL);
		printf("Ret=%d\n",ret);
	}
	semctl(id,1,SETVAL,4);
	printf("After :------------\n");
	
	for(i=0;i<5;i++)
	{
		ret=semctl(id,i,GETVAL);
		printf("Ret=%d\n",ret);
	}
	
}
