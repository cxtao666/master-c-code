#include <stdio.h>
int main()
{
  int a,b,c;
  float g,e;
  printf("Input math1, English and math2:");
  scanf("%d%d%d",&a,&b,&c);
  e=a*5.0+b*1.5+c*3.5;
  g=e/10.0;
  printf("Final score = %.2f\n",g);
  return 0;
}
