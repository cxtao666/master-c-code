#include <stdio.h>
void main()
{  
  float p,b;
  printf("Input payment p:");
  scanf("%f",&p);
  b=p*(1-0.08);
  printf("price = %.1f\n",b);
}