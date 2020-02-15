#include"header.h"
void main()
{
	int fd;
	char s[30];
	mkfifo("1",0666);
	perror("mkfifo");
	fd=open("1",O_RDWR);
	perror("open");
	read(fd,s,sizeof(s));
	printf("Data: %s\n",s);
	printf("Done\n");
}
