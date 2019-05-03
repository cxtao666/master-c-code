#include <stdio.h>
void main()
{
 float a,b,c,d;
   printf("Input percent of A and B:");
   scanf("%f%f",&a,&b);
   c=10*a+6*b;
   d=8*a+10*b;
   printf("compete = %.4f\nstandard = %.4f\n",c,d);
   if (c>d)
    printf("The Best Response is compete!");
   else printf("The Best Response is standard!");



}