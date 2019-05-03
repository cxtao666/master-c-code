#include <stdio.h>
int main()
{  int a,b,c;
   printf("Input your birth year:");
   scanf("%d",&a);
   printf("Input this year:");
   scanf("%d",&b);
   c=0;
    for (a=a;a<=b;a++)
    { if (a%400==0) 
	{ printf ("%d\n",a);  	  c=c+1;} 
      if (a%4==0&&a%100!=0)  
	  
	 { printf("%d\n",a);
	  c=c+1; } 
	   
	}
   printf ("count=%d\n",c) ;
	return 0;
}
