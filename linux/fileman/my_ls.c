#include<stdio.h>
#include<sys/types.h>
#include<dirent.h>
main()
{
	DIR *dp;
	struct dirent *v;
	dp=opendir("../fileman");
	if(dp==0)
	{
		perror("opendir");
		return;
	}
	while((v=readdir(dp))!=0)
	{
		if(v->d_name[0]=='.')
			continue;
		else
			printf("%s  ",v->d_name);
	}
	printf("\n");
}
