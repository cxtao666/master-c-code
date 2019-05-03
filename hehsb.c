
#include<stdio.h>
void main()
{
   int a[2] [2],i,j;
   for (i=0;i<2;i++)
	for (j=0;j<2;j++)
		scanf ("%d",&a[i][j]);
		for (i=0;i<2;i++ )
		{
		printf("\n");
		for ( j=0;j<2;j++)
			printf("%d\t",a[i][j]);
		
		}
		printf ("\n");



}
