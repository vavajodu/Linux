#include"header.h"
pthread_mutex_t m1,m2,m3;
void *thread_1(void *p)
{
	char i;
	for(i='a';i<='z';i++)
	{	
		pthread_mutex_lock(&m1);
		printf("%c\t",i);
		fflush(stdout);
		sleep(1);
		pthread_mutex_unlock(&m2);
	}
}
void *thread_2(void *p)
{
	char i;
	for(i='A';i<='Z';i++)
	{	
		pthread_mutex_lock(&m2);
		printf("%c\t",i);
		fflush(stdout);
		sleep(1);
		pthread_mutex_unlock(&m3);
	}
}
void *thread_3(void *p)
{
	char i;
	for(i=1;i<=26;i++)
	{	
		pthread_mutex_lock(&m3);
		printf("%d\n",i);
		fflush(stdout);
		sleep(1);
		pthread_mutex_unlock(&m1);
	}
}
void main()
{
	pthread_t t1,t2,t3;
	pthread_mutex_init(&m1,NULL);
	pthread_mutex_init(&m2,NULL);
	pthread_mutex_init(&m3,NULL);
	pthread_mutex_lock(&m2);
	pthread_mutex_lock(&m3);
	pthread_create(&t1,NULL,thread_1,NULL);
	pthread_create(&t2,NULL,thread_2,NULL);
	pthread_create(&t3,NULL,thread_3,NULL);
	pthread_exit(0);
}

