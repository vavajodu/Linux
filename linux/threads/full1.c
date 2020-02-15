#include"header.h"
void *thread_1(void *p)
{
	int fd;
	char data[30];
	fd=open("f1",O_RDONLY);
	while(1)
	{
		read(fd,data,sizeof(data));
		printf("Data:%s\n",data);
	}
}
void *thread_2(void *p)
{
	int fd;
	char data[30];
	fd=open("f2",O_WRONLY);
	while(1)
	{
		printf("Enter the data\n");
		scanf(" %[^\n]",data);
		write(fd,data,strlen(data)+1);
	}
}
void main()
{
	pthread_t t1,t2;
	mkfifo("f1",0644);	
	mkfifo("f2",0644);	
	pthread_create(&t1,NULL,thread_1,NULL);
	pthread_create(&t2,NULL,thread_2,NULL);
	while(1);
}
	
