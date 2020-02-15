#include"header.h"
void main()
{
	struct flock v;
	v.l_type=F_WRLCK;
	v.l_whence=SEEK_SET;
	v.l_start=0;
	v.l_len=0;
	char p[]="ABCDEFGHI";
	int fd,i;
	fd=open("data",O_RDWR|O_APPEND|O_CREAT,0666);
	if(fd<0)
	{
		perror("open");
		return;
	}
	printf("Before\n");
	fcntl(fd,F_SETLKW,&v);
	printf("After\n");
	for(i=0;p[i];i++)
	{
		write(fd,&p[i],1);
		sleep(1);

	}		
	v.l_type=F_UNLCK;
	fcntl(fd,F_SETLK,&v);		
	printf("Done\n");
}

