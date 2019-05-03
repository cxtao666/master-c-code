#include <stdio.h>
int Func(int n);
int main()
{
	int n;
	printf("Input n:");
	scanf("%d",&n);
	if(n<1000||n>1000000) printf("Input error!");
	if(n>=1000&&n<=1000000) printf("%d\n",Func(n));
	return 0;
}
int Func(int n)
{   int i;int max=0;
 	for(i=100;i<1000;i++)
	  if(n%i==0) 
	 { if(i>max)
	  max=i; }
	 return max;   
}
