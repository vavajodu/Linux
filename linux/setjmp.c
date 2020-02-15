#include<stdio.h>
#include<setjmp.h>
int sum(int,int);
int sub(int,int);
int mul(int,int);
int div(int,int);
jmp_buf v;
main()
{
	int n1,n2,n3,op,r;
	r=setjmp(v);
	if(r==3)
		printf("Error in mul function...\n");
	else if(r==4)
		printf("Error in div function..\n");
	printf("Enter two numbers...\n");
	scanf("%d %d",&n1,&n2);
	printf("Enter the option..\n");
	scanf("%d",&op);
	if(op==1)
	{
		n3=sum(n1,n2);
		printf("result=%d\n",n3);
	}
	else if(op==2)
	{
		n3=sub(n1,n2);
		printf("result=%d\n",n3);
	}
	else if(op==3)
	{
		n3=mul(n1,n2);
		printf("result=%d\n",n3);
	}
	else if(op==4)
	{
		n3=div(n1,n2);
		printf("result=%d\n",n3);
	}
	else
	{
		printf("Unknown option...\n");
	}
}
int sum(int a,int b)
{
	return (a+b);
}
int sub(int a,int b)
{
	return (a-b);
}
int mul(int a,int b)
{
	if(a==0|b==0)
		longjmp(v,3);
	else
		return (a*b);
}
int div(int a,int b)
{
	if(b==0)
		longjmp(v,4);
	else 
		return (a/b);
}
