#include"header.h"
int search(const char *);
void main()
{
	int fd;
	int n;
	char path[100];
	mkfifo("c",0666);
	fd=open("c",O_RDWR);	
	read(fd,path,sizeof(path));
	n=search(path);
	printf("%d\n",n);
	write(fd,&n,sizeof(int));
	printf("Done\n");
}
int search(const char *p)
{
	struct stat v;
	struct dirent *m;	
	int c=0;
	DIR *dp;
	stat(p,&v);
	dp=opendir(p);
	perror("opendir");
	while(m=readdir(dp))
	{
		if(m->d_type==S_ISREG(v.st_mode))
			c++;
	}
	return c;
}
