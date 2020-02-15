#include"header.h"
void *thread_1(void *p)
{
	int fd;
	char data[30];
	fd=open("f1",O_WRONLY);				//opening f1 fifo in wr only mode
	while(1)
	{
		printf("Enter the data\n");
		scanf(" %[^\n]",data);
		write(fd,data,strlen(data)+1);			//writing data
	}
}
void *thread_2(void *p)
{
	int fd;
	char data[30];
	fd=open("f2",O_RDONLY);				//opening f2 in rd only mode
	while(1)
	{
		read(fd,data,sizeof(data));		//reading data
		printf("Data:%s\n",data);
	}
}
void main()
{
	pthread_t t1,t2;
	mkfifo("f1",0644);		//creating f1 and f2 fifo
	mkfifo("f2",0644);	
	pthread_create(&t1,NULL,thread_1,NULL);		//creating thread
	pthread_create(&t2,NULL,thread_2,NULL);		//creating thread
	while(1);		//making main thread alive
}
	
