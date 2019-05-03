#include <stdio.h>
void main()
{  
  int a,b,c,d,max,min,e,f;
  printf("Input time one(hour, minute):");
  scanf("%d%d",&a,&c);
    printf("Input time two(hour, minute):");
	scanf("%d%d",&b,&d);
     if  (a>b)
	 {  
		  if (c>d)
	{max=a; min=b; e=c-d; f=max-min;}
	
	else if (c<d)
	{
	  max=a;min=b; e=c+60-d; f=max-min-1;
	}
	else { max=a; min=b; e=c-d; f=max-min;}
	}
     if (b>a) 
	 { 
		 if(d>c)
	 {  e=d-c;f=b-a;}
	 
	 else if (d<c)
	  
	 {e=d-c+60; f=b-a-1;}
	 
	 else  {e=d-c;f=b-a; } 
	 
	 }
	 printf("%d hour %d minute\n",f,e);

}