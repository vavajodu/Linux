#include"header.h"
struct msgbuf{
		long msg_type;		//msg_type>0
		char data[30];		//message
	};

void main(int argc,char **argv)
{
	if(argc!=3)
	{
		printf("Usage:./fname id data\n");
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
	v.msg_type=atoi(argv[1]);
	strcpy(v.data,argv[2]);
	msgsnd(fd,&v,strlen(v.data)+1,0);
	perror("msgsnd");
}
