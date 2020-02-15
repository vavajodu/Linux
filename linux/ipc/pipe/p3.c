#include"header.h"
void main()
{
	int p[2];
	int i;
	pipe(p);
	if(fork()==0)
	{
		char t[20];
		read(p[0],t,sizeof(t));
		printf("Data:%s\n",t);
		for(i=0;t[i];i++)
			if(t[i]>='a' && t[i]<='z')
				t[i]=t[i]-32;
		write(p[1],t,strlen(t)+1);
	}
	else
	{
		char s[20];
		printf("Enter the data\n");
		scanf(" %[^\n]",s);
		write(p[1],s,strlen(s)+1);
		sleep(2);
		read(p[0],s,sizeof(s));
		printf("Modified data:%s\n",s);
		while(1);
	}
}
