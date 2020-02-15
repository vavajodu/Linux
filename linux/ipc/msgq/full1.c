#include"header.h"
struct st{
	long m_type;
	char data[50];	
	};
void main()
{
	int fd;
	char p[50];
	struct st v,v1;
	fd=msgget(5,IPC_CREAT|0644);
	if(fd<0)
	{
		perror("msgget");
		return;
	}
	if(fork()==0)
	{
		while(1)
		{
			msgrcv(fd,&v1,sizeof(v1),1,0);
			printf("Data:%s\n",v1.data);
		}
	}
	else
	{
		while(1)
		{
			printf("Enter the data\n");
			scanf(" %[^\n]",p);
			strcpy(v.data,p);
			v.m_type=2;
			msgsnd(fd,&v,strlen(v.data)+1,0);
		}
	}
}
