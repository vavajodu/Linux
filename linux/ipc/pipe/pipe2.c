#include"header.h"
main()
{
	int p[2];
	int fp;	
	pipe(p);
	if(fork())
	{
		char b[20];
		fp=open("data",O_RDONLY);
		if(fp<0)
		{
			perror("open");
			return;
		}
		read(fp,b,sizeof(b));
		sleep(1);
		write(p[1],b,strlen(b)+1);
	}
	else
	{
		int i;
		char a[20];
		printf("in chils\n");
		read(p[0],a, sizeof(a));
		for(i=0;a[i];i++)
		{
			if(a[i]>='a'&a[i]<='z')
				a[i]=a[i]-32;
		}
		fp=open("data1",O_WRONLY|O_TRUNC|O_CREAT,0644);
		write(fp,a,strlen(a)+1);
	}
}
