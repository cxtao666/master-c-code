#include <stdio.h>
#include <math.h>
void main()
{
  int b;
  double a,c,g,d,e;
  char f;
  printf("Input capital, year:");
  scanf("%lf%d",&c,&b);
   printf("Compound interest (Y/N)?");
   scanf(" %c" ,&f);
   if (b==1)  a=0.0225;
   else if (b==2) a=0.0243;
   else if (b==3) a=0.0270;
   else if  (b==5) a=0.0288;
   else if  (b==8)  a=0.0300;
   else printf ("Error year!");

   if  (f=='y'||f=='Y')
   { 
     g=pow(1+a,b);
	 d=c*g;
	 printf("rate = %.4f, deposit = %.4f\n",a,d);
   }
   if(f=='N'||f=='n')
   {
	   e=c*(1+a*b);
     printf("rate = %.4f, deposit = %.4f\n",a,e);
   
   }
}