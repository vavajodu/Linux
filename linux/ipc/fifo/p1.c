#include"header.h"
void main()
{
	int fd;
	char s[30];
	mkfifo("1",0666);
	perror("mkfifo");
	fd=open("1",O_RDWR);
	perror("open");
	printf("enter the data\n");
	scanf(" %[^\n]",s);
	write(fd,s,strlen(s)+1);
	printf("Done\n");
}
