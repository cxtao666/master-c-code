
#include <stdio.h>
#include <math.h>
void main()
{ 
   int a,b,c,d,e;
   scanf("%d%d",a,b);
   c=a/b;d=a-c*b;
   e=a-(c-1)*b;
   printf("negative: %d\n",d);
   printf("positive: %d\n",e);


}
