#include"header.h"
void *thread1(void *p)
{
	printf("In thread1...%d\n",*(int *)p);		//catching "hello" by char *
	sleep(10);
	pthread_exit("bye");				//terminating thread with returning string
}
void main()
{
	void *p;
	int i=10;
	pthread_t t1,t2;
	pthread_create(&t1,NULL,thread1,&i);	//passing string "hello"	
	printf("Before\n");
	pthread_join(t1,&p);				//joining by catching return value of pthread_exit() with void pointer
	printf("After\n");
	printf("%s\n",(char *)p);				//printing return value
	printf("In main() while1\n");
	while(1);					//making main thread alive
}
