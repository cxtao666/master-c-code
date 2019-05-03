#include <stdio.h> 
int fun(int n);
int main()
{
 int a,b,c;
 scanf("%d",&a)	;
 b=fun(a);
 c=b%10007;
 printf("%d",c);
 return 0;
}
int fun(int n)
{
   if(n==1||n==2) return 1;
   else  return fun(n-1)+fun(n-2) ;
}

