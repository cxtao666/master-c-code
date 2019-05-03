#include<stdio.h>
#define N 1000
main()
{
	int n,i,f,k=0;
	int t=0,j=0,r=0;
	char a[N][5];
	char b[3][5]={"tom","jack","rose"};
	printf("Input the number of electorates:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Input vote %d:",i+1);
		scanf("%s",a[i]);
	}	
	for(i=0;i<n;i++)
	{
		if((a[i][0])=='t')
		{
			for(f=0;b[0][k]!='\0';f++)
			{
				if((a[i][f])==(b[0][k]))
					k++;
				else
				break;	
			}
			if((b[0][k]=='\0')&&(a[i][f]=='\0'))
			 	t++;
		}
		if((a[i][0])=='j')
		{
			for(f=0;b[1][k]!='\0';f++)
			{
				if((a[i][f])==(b[1][k]))
					k++;
				else
				break;	
			}
			if((b[1][k]=='\0')&&(a[i][f]=='\0'))
			 	j++;
		}
		if((a[i][0])=='r')
		{
			for(f=0;b[2][k]!='\0';f++)
			{
				if((a[i][f])==(b[2][k]))
					k++;
				else
				break;	
			}
			if((b[2][k]=='\0')&&(a[i][f]=='\0'))
			 	r++;
		}
		k=0; 
	}
	printf("Election results:\n");
	printf("%s:%d\n",b[0],t);
	printf("%s:%d\n",b[1],j);
	printf("%s:%d\n",b[2],r);
	if((t>=j)&&(t>=r))
	printf("%s wins\n",b[0]);
	if((j>=t)&&(j>=r))
	printf("%s wins\n",b[1]);
	if((r>=t)&&(r>=j))
	printf("%s wins\n",b[2]);
}
