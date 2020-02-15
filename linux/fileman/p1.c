#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
main(int argc,char **argv)
{
	struct stat v;
	if(argc!=2)
	{
		printf("Usage:./a.out fname\n");
		return;
	}
	if(stat(argv[1],&v)<0)
	{
		perror("stat");
		return;
	}
	printf("%ld....inode-%ld\n",v.st_size,v.st_ino);
}
	
