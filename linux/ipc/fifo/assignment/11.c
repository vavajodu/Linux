#include"header.h"
void main()
{
	int fd,i,j=0,k;
	mkfifo("a",0666);
	char s[30];
	char a[30];
	fd=open("a",O_RDWR);
	read(fd,s,sizeof(s));
	for(i=0;s[i];i++)
	{
		if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
			continue;
		else
		{
			a[j++]=s[i];
			for(k=i;s[k];k++)
				s[k]=s[k+1];
			i--;
		}
	}
	a[j]='\0';
	printf("Character array:%s\n",s);
	printf("Integer array:%s\n",a);
	printf("\n");
	printf("Done\n");
}
