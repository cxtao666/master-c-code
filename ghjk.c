#include <stdio.h>
void main()
{
     int a,b,c;
    float e,f,g;
      c=4321;
	 a=4321/100;
	 b=4321%100;
	 f=a;g=b;
	  e=f/g;
	  printf("a=%d,b=%d\n",a,b);
	  printf("a+b=%d\n",a+b);
	  printf("a-b=%d\n",a-b);
	  printf("a*b=%d\n",a*b);
	  printf("a/b=%.2f\n",e);
	  printf("a%%b=%d\n",a%b);
}