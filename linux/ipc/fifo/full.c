#include"header.h"
void main()
{
	int fd,fd1;
	mkfifo("f1",0666);
	mkfifo("f2",0666);
	if(fork()==0)
	{
		char a[30];
		while(1)
		{
			fd1=open("f2",O_RDWR);
			read(fd1,a,sizeof(a));
			printf("Data:%s\n",a);
		}
	}
	else
	{
		char s[30];
		while(1)
		{
			fd=open("f1",O_RDWR);
			printf("Enter the data\n");
			scanf(" %[^\n]",s);
			write(fd,s,strlen(s)+1);
		}
	}
}
