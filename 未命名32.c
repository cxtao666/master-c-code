#include <stdio.h>
int main()
{
  int n,i,j,c;
  printf("Input n:");
  scanf("%d",&n);
  printf("Input %d*%d matrix:\n",n,n);
  int a[n][n];
  
  for (c=0;c<n;c++)
  {
  	for (j=0;j<n;j++)
  	{scanf("%d",&a[c][j])}
  	printf("\n");
  }
  for(c=0;c<n;c++)	
  {
  	for(j=0;j<n;j++)
  	{printf("%d",a[j][c]);printf(" ");}
  	printf("\n");
  }
	return 0;
}
