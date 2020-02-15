#include"header.h"
void main()
{
	int p[2],i;
	pipe(p);
	if(fork()==0)
	{
		FILE *fd;
		char s[30];
		while(1)
		{
			read(p[0],s,sizeof(s));
			for(i=0;s[i];i++)
			{
				if(s[i]>='a' && s[i]<='z')
					s[i]=s[i]-32;
			}
			fd=fopen("data1","w");
			fprintf(fd,"%s",s);
			fclose(fd);
		}
	}
	else
	{
		FILE *fd;
		char s[30];
		fd=fopen("data","r");
		while(fscanf(fd,"%s",s)!=EOF)
		{
			write(p[1],s,strlen(s)+1);
		}
		fclose(fd);
		printf("Done\n");
		while(1);
	}
}
