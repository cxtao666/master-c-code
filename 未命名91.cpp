#include <stdio.h>
int Fun(int n)
{   if (n==1) return 1;
    else return Fun(n-1)+1;
}
 
int main()
{   
   int i,j=0;
    for(i=1;i<3;i++) j+=Fun(i);
   printf("%d\n",j);
    return 0;
}


