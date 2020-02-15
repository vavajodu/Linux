#include"header.h"
void main()
{
	int md;
	md=msgget(2,IPC_CREAT|0644);
	if(md<0)
	{
		perror("msgget");
		return;
	}
	printf("Id=%d\n",md);
}
