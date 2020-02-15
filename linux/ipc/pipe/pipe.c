#include<stdio.h>
#include<unistd.h>
#include<string.h>
main()
{
	int p[2];
	pipe(p);
	perror("pipe");
	if(fork()==0)
	{
		int i;
		char a[20];
		printf("In child\n");
		read(p[0],a,sizeof(a));
		for(i=0;a[i];i++)
		{
			if(a[i]>='a' && a[i]<='z')
				a[i]=a[i]-32;
			else if (a[i]>='A' && a[i]<='Z')
				a[i]=a[i]+32;
		}
		write(p[1],a,strlen(a)+1);
		

	}
	else
	{
		char s[20];
		printf("Enter the string...\n");
		gets(s);
		write(p[1],s,strlen(s)+1);
		sleep(2);
		read(p[0],s,sizeof(s));
		printf("After written by child\n");
		printf(" %s\n",s);
		while(1);
	}
}
