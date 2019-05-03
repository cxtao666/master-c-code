 

#include "stdio.h"
int main()
{
   int num;
   char c;
   num=0;
   printf("Input your password:\n");
   while (num<  6)
   {
       scanf("%c%*c",&c);
       if (c>='0'&&c<='9')
       {
           num++;
           printf("%c, you have enter %d-bits number\n",c,num);
       }
       else printf("error\n");
   }
}
