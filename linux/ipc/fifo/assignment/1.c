#include"header.h"
void main()
{
	int fd;
	mkfifo("a",0666);
	char s[30];
	fd=open("a",O_RDWR);
	printf("Enter the data\n");
	scanf(" %[^\n]",s);
	write(fd,s,strlen(s)+1);
	printf("Done\n");
}
