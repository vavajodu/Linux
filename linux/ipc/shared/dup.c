#include"header.h"
void main()
{
	int fd;
	char data[]="hello";
	fd=dup(1);
	write(fd,data,strlen(data)+1);
	printf("Done");
}
