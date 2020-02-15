#include"header.h"
void main()
{
	struct sembuf v;
	int id,fd,i;
	char ch='A';
	id=semget(5,5,IPC_CREAT|0666);
	if(id<0)
	{
		perror("semget");
		return;
	}
	fd=open("data",O_RDWR|O_APPEND|O_CREAT,0644);	
	if(fd<0)
	{
		perror("open");
		return;
	}
	v.sem_num=2;
	v.sem_op=0;
	v.sem_flg=0;
	for(;ch<='Z';ch++)
	{
		semop(id,&v,1);
		semctl(id,2,SETVAL,1);				//setting 2nd subsemaphore value
		semctl(id,1,SETVAL,1);				//setting 1st subsemaphore value so w1 will not access resource
		write(fd,&ch,1);				//writing data
		semctl(id,1,SETVAL,0);				//setting 1st semaphore value so w1 will access resource
	}
	printf("Done\n");
}
