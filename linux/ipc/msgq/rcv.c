#include"header.h"
struct msgbuf{
		long msg_type;		//msg_type>0
		char data[30];		//message
	};

void main(int argc,char **argv)
{
	if(argc!=2)
	{
		printf("Usage:./fname id\n");
		return;
	}
	int fd;
	struct msgbuf v;
	fd=msgget(1,IPC_CREAT|0644);
	if(fd<0)
	{
		perror("msgget");
		return;
	}
	msgrcv(fd,&v,sizeof(v.data),atoi(argv[1]),0);
	perror("msgrcv");
	printf("Data:%s\n",v.data);
}
