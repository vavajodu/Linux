#include"header.h"
void main()
{
	int fd;
	int n;
	char path[100];
	mkfifo("c",0666);
	printf("Enter the string\n");
	scanf(" %[^\n]",path);
	fd=open("c",O_RDWR);	
	write(fd,path,strlen(path)+1);
	printf("Done\n");
	sleep(2);
	read(fd,&n,sizeof(int));
	printf("There are %d files in directory\n",n);
}
	
