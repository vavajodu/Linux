#include"header.h"
void main()
{
	int fd,fd1;
	char s[30];
	mkfifo("h1",0666);
	mkfifo("h2",0666);
	while(1)
	{
		fd=open("h1",O_RDWR);
		printf("enter the data\n");
		scanf(" %[^\n]",s);
		write(fd,s,strlen(s)+1);
		fd1=open("h2",O_RDWR);
		read(fd1,s,sizeof(s));
		printf("Data:%s\n",s);
	}
}
		
	
