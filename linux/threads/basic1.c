#include"header.h"
void *thread1(void *p)
{
	printf("In thread1...%d\n",*(int *)p);		//catching "hello" by char *
	pthread_join(pthread_self(),NULL);
}
void main()
{
	pthread_t t1,t2;
	pthread_create(&t1,NULL,thread1,NULL);
	printf("In main..\n");
	while(1);
}
