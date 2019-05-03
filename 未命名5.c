#include <stdio.h>
int main()
{  int a,b,c,d,e,f,g;
   printf("Input your birth year:");
   scanf("%d",&a);
   printf("Input this year:");
   scanf("%d",&b);
   d=a;e=b;
   c=0;
    for (a=a;a<=b;a++)
    { if (a%400==0) 
	{  c=c+1;} 
      if (a%4==0&&a%100!=0)  
	  
	 { c=c+1; } 
	   
	}
    f=(e-d)*365+c-1;
    g=f*24*60*75;
    printf("The heart beats in your life: %lu",g);
	return 0;
}
