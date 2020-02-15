#include"header.h"
void main()
{
	int fd,fd1;
	mkfifo("b",0666);
	mkfifo("bb",0666);
	char s[30];
	char a[30];
	fd=open("b",O_RDWR);
	printf("Enter the data\n");
	scanf(" %[^\n]",s);
	write(fd,s,strlen(s)+1);
	printf("Done\n");
	fd1=open("bb",O_RDWR);
	read(fd1,a,sizeof(a));
	printf("%s\n",a);
	sleep(2);
	read(fd1,a,sizeof(a));
	printf("%s\n",a);
	
}
