#include<stdio.h>
#include<setjmp.h>
int sum(int,int);
int sub(int,int);
int mul(int ,int);
int div(int,int);
jmp_buf v;
main()
{
	int n1,n2,n3,r,op;
	r=setjmp(v);
	if(r==3)
		printf("Erro in mul function\n");
	else if (r==4)
		printf("Error in div function\n");
	printf("Enter n1 and n2..\n");
	scanf("%d %d",&n1,&n2);
	printf("Enter the option\n");
	scanf("%d",&op);
	if (op==1)
	{
		n3=sum(n1,n2);
		printf("n3=%d\n",n3);
	}
	else if (op==2)
	{
		n3=sub(n1,n2);
		printf("n3=%d\n",n3);
	}
	else if (op==3)
	{
		n3=mul(n1,n2);
		printf("n3=%d\n",n3);
	}
	else if (op==4)
	{
		n3=div(n1,n2);
		printf("n3=%d\n",n3);
	}
}
int sum(int i,int j)
{
	return (i+j);
}
int sub(int i,int j)
{
	return (i-j);
}
int mul(int i,int j)
{
	if(i==0|j==0)
		longjmp(v,3);
	return (i*j);
}
int div(int i,int j)
{
	if(j==0)
		longjmp(v,4);
	return (i/j);
}
