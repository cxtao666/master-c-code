#include<stdio.h>
int Gcd(int a, int b);
int main()
{  int m,n;
  printf("Input m,n:");
   	 scanf("%d%d",&m,&n );
	if( Gcd(m, n)==-1) printf("Input error!\n");
	return 0;
}
int Gcd(int a, int b)
{  int max1=a,max2=b;int i,j;
  if(b<=0) return -1;
	else if(a>10000||a<0) return -1;
	else  {
	 for(i=a;i>0;i--)
	  {
	    for(j=b;j>0;j--)
		 {
		  if((double)i/j==(double)a/b)  { 
		 if(j<=max2) {  
		 max1=i; max2=j;
		 }
	}}
}  printf("%d/%d\n",max1,max2);return 0;}
	}

