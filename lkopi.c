#include <stdio.h>
#include <math.h>
void main()
{
  int a;
  double b,c,d,e,g;
  char f;
  printf("Input rate, year, capital:");
  scanf( "%lf,%d,%lf",&b,&a,&c);
   printf("Compound interest (Y/N)?");
   scanf(" %c" ,&f);
   if  (f=='y'||f=='Y')
   { 
     g=pow(1+a,b);
	 d=c*g;
	 printf("deposit = %.4f\n",d);
   }
   if(f=='N'||f=='n')
   {
	   e=c*(1+a*b);
     printf("deposit = %.4f\n",e);
   
   }
}