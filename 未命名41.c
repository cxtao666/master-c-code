#include <stdio.h> 
int Sum(int n);
int main()
{    int a,b;
	printf("Please input n:");
	scanf("%d",&a);
	if(a>0)
	{
	b=Sum(a);
	printf("sum=%d\n",b);
}
   else printf("data error!\n");
}

int Sum(int n)
{    if (n==1) return 1;
     else  return  n=n+Sum(n-1);
}	
	
	
	
	
	
	

