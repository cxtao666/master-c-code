#include <stdio.h>
int main()
{int a,b,c;
a=1;b=1;c=1;
for (a=1;a<=30;a++)
{for(b=1;b<=30;b++)
{c=30-a-b;
if (c+2*b+3*a==50)
{ printf ("Man   Women   Children\n");
printf("%3d%8d%8d\n",a,b,c);
}}}
return 0;
}
