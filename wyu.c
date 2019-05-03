#include <stdio.h>
#include <math.h>
void main()
{  int a,b,c;
   float g,d,e,f;
  printf("Input math1, English and math2:");
  scanf("%d,%d,%d",&a,&b,&c);
   d=a;e=b;f=c;
  g  =(d*5+e*1.5+f*3.5)/10;
  printf("Final score = %.2f\n",g);

}