#include <stdio.h>
void main()
{  
  int a,b,c,d,max,min,e,f;
  printf("Input time one(hour, minute):");
  scanf("%d%d",&a,&c);
    printf("Input time two(hour, minute):");
	scanf("%d%d",&b,&d);
	if  (c>d)
	{
	  e=c-d;
	}
    else 
	{
	  e=c+60-d;a=a-1;
	}
     if (a>b)
    {  
     max=a; min=b;
	}
	else
	{
	  max=b;min=a;
	}
    f=max-min;
	printf("%d hour %d minute\n",f,e);

}