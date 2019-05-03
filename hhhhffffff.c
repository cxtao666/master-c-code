#include <stdio.h>
void main ()
{
  int a,b,c,d;
  float e,f;
  printf("Input a/b, c/d:" );
  scanf("%d/%d%d/%d",&a,&b,&c,&d);
  e=(float)a/b;
  f=(float)c/d;
  if (e>f)
  printf("%d/%d>%d/%d\n",a,b,c,d);
  else if (e<f)
	  printf("%d/%d<%d/%d\n",a,b,c,d);
   else printf("%d/%d=%d/%d\n",a,b,c,d);
}





