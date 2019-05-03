#include <stdio.h>
int main()
{
 int i,n,d,b,c,f;
  scanf("%d",&i);
  int a[i];
  for(n=0;n<i;n++)
  {
  	scanf("%d",&a[n]);
  }
	for(d=0;d<i;d++)
	 { for (b=d+1;b<i;b++)
	    { for(c=b+1;c<i;c++)
	    	if(a[d]+a[b]==a[c])
	    	f++;
		}
	
}
	
   printf("%d",f);
   return 0;	
}
