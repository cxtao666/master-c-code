#include <stdio.h>
int main ()
{   int n,i ;
   float a,b,c;
   a=100;b=100;c=50;
   printf("Input:\n");
    scanf("%d",&n);
   for (i=1;i<n;i++)
   {
   	a=a/2;
   	b=b+2*a;
   	c=c/2;
   }
   printf("%d times:\n",n);
   printf("%.3f\n",b);
   printf("%.3f\n",c);

	
   return 0;	
}
