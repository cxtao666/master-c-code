#include <stdio.h>
#include <math.h>
void main()
{ 
   int x ,a,b,c,d ;
    printf("input x:\n");
   scanf("%d", &x);
   fabs(x);
   a=x/100; b=(x%100)/10;c=(x%100)%10;
   d=c*100+b*10+a;
   printf("y=%d\n",d);
   return;
}