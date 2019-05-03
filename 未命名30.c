#include <stdio.h>
int main()
{
  int n,i,a,b,c,d;
  	for(i=1000;i<10000;i++)
  	{
  	 a=i/1000;
  	 b=i/100-a*10;
  	 c=i/10-a*100-b*10;
  	 d=i%10;
  	 if(i==a*a*a*a+b*b*b*b+c*c*c*c+d*d*d*d)
  	 printf("%d\n",i);
	  }
	 return 0; 
	
}
