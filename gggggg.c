#include <stdio.h>
void main()
{  int a,b;
   if ( scanf("%d",&a)==1 )
   { 
	   if(scanf("%d",&b)==1 )
	   {printf ("a = %d, b = %d\n" ,a,b);}
	   else {printf("Input error!");}
    }
   else {
     printf("Input error!");
   }

  }
