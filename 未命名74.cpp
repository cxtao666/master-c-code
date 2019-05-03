#include<stdio.h>
int IsPrime(int x);
int main()
{   int n,sum=0,i;
	printf("Input n:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	 if(IsPrime(i)==1) sum=i+sum;
	printf("sum=%d\n",sum);
	return 0;
}
int IsPrime(int x)
{   int i;
   for(i=2;i<=x;i++)
	if(x%i==0) break;
	if(i==x) return 1;
	 else return 0;
}
