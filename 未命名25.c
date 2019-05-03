#include <stdio.h>
int main()
{  
   int a,i,c,e,f,n,b,g,h;
   c=0;
   e=0;
   f=0;
   scanf("%d",&a);
   n=10;
   if(a<n)
   {
     switch (a)
    {
    case 1: c=c+1;break;
    case 2: e=e+1;break;
    case 3: f=f+1;break;	
	}
   }
   while (n<a)
   { 
    b=a%n;
    g=b*10/n;
    switch (g)
    {
    case 1: c=c+1;break;
    case 2: e=e+1;break;
    case 3: f=f+1;break;	
	}
   	 n=n*10;
   } 
   h=a*10/n;
   switch (h)
    {
    case 1: c=c+1;break;
    case 2: e=e+1;break;
    case 3: f=f+1;break;	
	}
   
   
printf("%d %d %d",c,e,f);
return 0;
}
