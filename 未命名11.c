#include <stdio.h>
int main()
{
	int n,b,x,i;
	b=1;x=0;
	printf("Input days:\n");
	scanf("%d",&n);
	
	for(i=1;i<n;i++)
{
     b=2*(b+1);
	}
	printf("x=%d\n",b);
 return 0;	
	
	 
}
