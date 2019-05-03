#include<stdio.h>
#include<stdbool.h>
int main(void)
{
   bool prime;
   int prime_pti[100];
   int prime_z=0;
   int i,n,p=0;
   int a,b;
   int step=0;
   for(prime=true,i=1;i<=500;i++)  /*找出500内的所有素数*/
   {
      for(n=2;(n*n)<=i;n++)    /*判断一个数是否是素数*/
      {
         if(i%n==0)
         {
            prime=false;
            break;
         }
      }
      if(prime)       /*是素数就存储在数组中*/
      {
        prime_pti[p]=i;
        p++;
      }
      prime=true;
   }
   for(a=0;a<p-1;a++)    /*从大到小排序素数数组*/
      for(b=a+1;b<p;b++)
      {
         if(prime_pti[a]<prime_pti[b])
         {
           step=prime_pti[a];
           prime_pti[a]=prime_pti[b];
           prime_pti[b]=step;
         }
      }
   if(p>9)           /*判断素数个数是否达到10，是则输出，否则退出。*/
   {
     for(i=0;i<10;i++)
     {
        if(i<9)
          printf("%d+",prime_pti[i]);
        else
        {
          printf("%d=",prime_pti[i]);
          for(n=0;n<10;n++)
             prime_z+=prime_pti[n];
          printf("%d\n",prime_z);
        }
     }
   }
   else
     printf("Sorry!\n");
   return 0;
}
