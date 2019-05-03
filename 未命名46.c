#include <stdio.h>
int main()
{  int m,i,sum1,sum2,sum3,a,b,c,d,e,f;
   sum1=1; sum2=1;sum3=1;
   for(m=100;m<1000;m++)
   {
   	  a=m/100;
   	  b=(m/10)%10;
   	  c=m%10;
   	  for(d=1;d<=a;d++)  sum1=d*sum1;
   	  for(e=1;e<=b;e++)  sum2=e*sum2;
   	   for(f=1;f<=c;f++)  sum3=f*sum3;
   	   if(m==sum1+sum2+sum3)  printf("%ld\n",m);
   }
  	return 0;
}
