#include"header.h"
void main()
{
	int fd;
	dup2(1,7);
	write(7,"hello",6);
}
	
