#include <stdio.h>
#define N 100
void FindSaddlePoint(int a[][N], int m, int n);
int main()
{  int i,j;
   int m,n;
 printf("Input m,n:\n");
	scanf( "%d,%d",&m,&n);
	 int a[m][100];
	for(i=0;i<m;i++)
	 for(j=0;j<n;j++)
	   scanf("%d",&a[i][j]);
	 FindSaddlePoint(a,m,n);
	return 0;
}
void FindSaddlePoint(int a[][N], int m, int n)
{
	int i,j,max,k,c=0;
	int flag;
	 int flag0=0;
	for(i=0;i<m;i++)
	{   flag=0;
    	max=0;
	   for(k=0;k<n;k++)
	   if(a[i][0]<=a[i][k]) 
	    if(a[i][k]>max) 
	   {
	    max =a[i][k];
	    c=k;
		}
     for(j=0;j<m;j++)
      {
	    if(max<=a[j][c])  flag++;
           if(flag/m==1) {printf("a[%d][%d] is %d\n",i,c,max);flag0=1;}
}
}
       if( flag0==0 ) printf("No saddle point!\n");
}
