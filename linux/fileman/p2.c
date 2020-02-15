#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
main(int argc,char **argv)
{
	struct stat v,v1;
	if(argc!=3)
	{
		printf("Usage:./a.out fname f1name\n");
		return;
	}
	if(stat(argv[1],&v)<0)
	{
		perror("stat");
		return;
	}
	if(stat(argv[2],&v1)<0)
	{
		perror("stat");
		return;
	}
	if(v.st_ino==v1.st_ino)
	{
		if(lstat(argv[1],&v)<0)
		{
			perror("lstat");
			return;
		}
		if(lstat(argv[2],&v1)<0)
		{
			perror("lstat");
			return;
		}
		if(v.st_ino==v1.st_ino)
			printf("Hard link\n");
		else
			printf("Soft link\n");
	}
	else
		printf("No link is there...\n");
}
	
	
