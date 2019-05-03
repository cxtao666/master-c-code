#include <stdio.h>
int main()
{
  int a,i,j,n;
  n=0;
  scanf("%d",&a);
  int b[a],d[a];
   d[0]=0;
  for(i=0;i<a;i++)	
	scanf("%d",&b[i]);
	for(i=0;i<a;i++)
	{
	for(j=0;j<a;j++)
	
	 { if (b[i]>b[j]&&b[j]>d[i])  b[i]=b[j]; d[i]=b[j] ;}
	              
	
}
   for(i=0;i<a;i++)
   printf("%d",b[i]);
   return 0;
}
