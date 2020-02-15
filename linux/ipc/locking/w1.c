#include"header.h"
void main()
{
	struct flock v;
	char p[]="abcdefghi";
	int fd,i;
	v.l_type=F_WRLCK;
	v.l_whence=SEEK_SET;
	v.l_start=0;
	v.l_len=0;
	fd=open("data",O_RDWR|O_APPEND|O_CREAT,0666);
	if(fd<0)
	{
		perror("open");
		return;
	}
	printf("before\n");
	fcntl(fd,F_SETLKW,&v);
	for(i=0;p[i];i++)
	{
		write(fd,&p[i],1);
		sleep(1);
	}
	printf("Done\n");
	v.l_type=F_UNLCK;
	printf("Released\n");
}

