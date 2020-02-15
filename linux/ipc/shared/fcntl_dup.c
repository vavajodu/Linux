#include"header.h"
void main()
{
	int fd;
	fd=fcntl(1,F_DUPFD,0);
	printf("id=%d\n",fd);
	fd=dup2(1,3);
	printf("id=%d\n",fd);
}
