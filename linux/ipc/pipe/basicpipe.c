#include"header.h"
void main()
{
	int p[2];
	char str[20];
	pipe(p);
	if(fork()==0)
	{
		char b[20];
		printf("In child\n");
		read(p[0],b,sizeof(b));
		printf("Data: %s\n",b);
	}
	else
	{
		printf("In parent\n");
		printf("Enter the string\n");
		scanf(" %[^\n]",str);
		write(p[1],str,strlen(str)+1);
		printf("done\n");
		while(1);	//to make parent alive
	}
}
