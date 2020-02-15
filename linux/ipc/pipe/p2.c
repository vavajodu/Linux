#include"header.h"
void main()
{
	int p[2];
	pipe(p);
	char s[20];
	if(fork()==0)
	{
		char t[20];
		while(1)
		{
			read(p[0],t,sizeof(t));
			printf("Data:%s\n",t);
		}
	}
	else
	{
		while(1)
		{
			printf("Enter the data\n");
			scanf(" %[^\n]",s);
			write(p[1],s,strlen(s)+1);
		}
	}
}
