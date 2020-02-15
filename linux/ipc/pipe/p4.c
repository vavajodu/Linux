#include"header.h"
void main()
{
	int p[2],i;
	char ch[10];
	pipe(p);
	if(fork()==0)
	{
		char s[10];
		read(p[0],s,5);
		printf("Child1..Data:\n");
		for(i=0;i<5;i++)
			printf("%c ",s[i]);
		printf("\n");
	}
	else
	{
		printf("Parenti........%d\n",getpid());
		if(fork()==0)
		{
			char s[10];
			read(p[0],s,5);
			printf("Child2..Data:\n");
			for(i=0;i<5;i++)
				printf("%c ",s[i]);
			printf("\n");
		}
		else
		{
			printf("Enter the data\n");
			scanf(" %[^\n]",ch);
			write(p[1],ch,strlen(ch)+1);
			printf("Done\n");
			while(1);
		}		
	}
}
