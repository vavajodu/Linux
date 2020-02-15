#include<stdio.h>
main()
{
	if(fork()==0)
	{
		printf("In child..\n");
		while(1);
	}
	else
		printf("in parent...\n");

}
