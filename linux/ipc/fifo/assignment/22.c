#include"header.h"
void sort(char *,int);
void main()
{
	int fd,fd1,i,j=0,k;
	mkfifo("b",0666);
	mkfifo("bb",0666);
	char s[30];
	char a[30];
	fd=open("b",O_RDWR);
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
	sort(s,strlen(s));
	sort(a,strlen(a));
	fd1=open("bb",O_RDWR);
	write(fd1,s,strlen(s)+1);
	sleep(2);
	write(fd1,a,strlen(a)+1);
	printf("Done\n");
}
void sort(char *p,int n)
{
	int i,j;
	char temp;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(p[i]<p[j])
			{
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
		}
	}
}
