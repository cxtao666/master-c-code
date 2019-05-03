#include <stdio.h> 
#include <math.h>
double Y(double x, int n);
int main()
{
   double a,c; int b;
   printf("Please input x and n:");
   scanf( "%lf%d",&a,&b);
    c= Y(a,b);
    printf( "Result=%.2f\n",c);
}
double Y(double x, int n)
{
  if (n==1)  return sqrt(x);
     return  sqrt( x + Y(x,n-1));	
}
