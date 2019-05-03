#include <stdio.h>
int main()
{
    int b,i;
    float a,c,x,s;
	printf("Input length and days:");
	scanf("%f%d",&a,&b);
	c=a;
	for(i=0,x=0;i<b;i++) 
	{   
	  a=a/2;
      x=x+a;
	}
      s=c-x;
	printf("length=%.5f\n",s);
}
