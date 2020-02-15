#include"header.h"
void main()
{
	int id,ret;
	struct sembuf v;
	v.sem_num=1;
	v.sem_op=0;
	id=semget(5,5,IPC_CREAT|0666);
	if(id<0)
	{
		perror("semget");
		return;
	}
	semctl(id,1,SETVAL,4);
	ret=semctl(id,1,GETVAL);
	printf("%d\n",ret);
	printf("Before\n");
	semop(id,&v,1);
	printf("After\n");
	printf("Done\n");
}
