#include"header.h"
void main()
{
	struct sembuf v;
	int id,fd,i;
	char ch='a';
	id=semget(5,5,IPC_CREAT|0666);
	if(id<0)
	{
		printf("hi\n");
		perror("semget");
		return;
	}
	fd=open("data",O_RDWR|O_APPEND|O_CREAT,0644);	
	if(fd<0)
	{
		perror("open");
		return;
	}
	for(i=0;i<5;i++)
		semctl(id,i,SETVAL,0);
	v.sem_num=1;
	v.sem_op=0;
	v.sem_flg=0;
	for(;ch<='z';ch++)
	{
		semop(id,&v,1);
		semctl(id,1,SETVAL,1);				//setting value of 1st subsemaphore
		semctl(id,2,SETVAL,1);				//setting value of 2nd subsemaphore so w2 will block
		write(fd,&ch,1);				//writing data 
		sleep(1);
		semctl(id,2,SETVAL,0);				//allowing w2 to use resource by setting 2nd sub semaphore
	}
	printf("Done\n");
}
