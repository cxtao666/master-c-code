#include <stdio.h>
void main ()
{     
    int a;
	float b,c;
	scanf("%d,%f",&a,&b);
    if (a<=4&&a>=0,b>0)
    
	{	if (a==0)  c=(b/1)*3+10 ;                                                  
        else if (a==1)   c=(b/1)*4+10 ;
	    else if (a==2)   c=(b/1)*5+15;
		else if (a==3)   c=(b/1)*6.5+15;
		else  c=(b/1)*10+15;
      printf("Price: %5.2f\n",c);
}
    else  printf ("Error in Area\n"); 
	 

} 
