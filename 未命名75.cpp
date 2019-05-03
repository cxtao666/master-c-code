#include <stdio.h> 
int Monkey(int n, int x);
int main()
{
	int n;int x=0;
	printf("Input days n:");
	scanf("%d",&n);
	printf("x=%d\n",Monkey(n,x));
	return 0;
}
int Monkey(int n, int x)
{
	if(n==1) return 1;
	else return (Monkey(n-1,x)+1)*2; 
}
