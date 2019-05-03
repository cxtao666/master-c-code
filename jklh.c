#include <stdio.h>
#include <math.h>
void main ()
{     
    int a;
	float b,c,d;
	scanf("%d,%f",&a,&b);
    d=floor(b);
    if (a>=0&&a<=4)
	{   if (b>0) 
    
	{	if (a==0)  c=d*3+10 ;
        else if (a==1)   c=d*4+10 ;
	    else if (a==2)   c=d*5+15;
		else if (a==3)   c=d*6.5+15;
		else if (a==4)   c=d*10+15;
		else  printf ("Error in Area\n"); 
      printf("Price: %5.2f\n",c);
}
     else  printf ("Error in number\n");
    }
	else  printf ("Error in Area\n"); 
 } 
