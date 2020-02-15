#include"header.h"
void main()
{
	int id,ret;
	id=semget(5,5,IPC_CREAT|0666);	
	ret=semctl(id,1,GETVAL);
	printf("%d\n",ret);
	printf("done\n");
}
