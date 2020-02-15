#include"header.h"
void main()
{
	int id,ret;
	struct sembuf v;
	v.sem_num=1;
	v.sem_op=3;
	v.sem_flg=0;
	id=semget(5,5,IPC_CREAT|0666);
	if(id<0)
	{
		perror("semget");
		return;
	}
	ret=semctl(id,1,GETVAL);
	printf("Ret=%d\n",ret);
	printf("Before\n");
	semop(id,&v,1);
	ret=semctl(id,1,GETVAL);
	printf("REt=%d\n",ret);
	sleep(10);
	printf("After\n");
	ret=semctl(id,1,GETVAL);
	printf("Done\n");


}
