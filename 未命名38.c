#include<stdio.h> 
int main()
{
  int n,i,a,c,e,f,sum,g;
  printf("Input n(n<=500):");
  scanf("%d",&n);
  int b[n];
   e=n;
   sum=0;
  for(i=2;i<=n;i++)
  {
  	for(a=2;a<=i;a++)
  	{
  	  if(i%a==0) 
      break;
	  }
     if(a==i) 
    {
    	e=e-1;
	b[e]=i;
    }
}
  f=e+10;
  g=e;
  if(n-e>=10)
{ for(e=e;e<f;e++) 
 {printf("%6d",b[e]);
 }
   for (e=g;e<f;e++) 
     sum=b[e]+sum;
      printf("\nsum=%d\n",sum);
	
  }
  else if(n-e<10)
    {
    for(e=e;e<n;e++)	
    {printf("%6d",b[e]);
 }
  for(e=g;e<n;e++) 
     sum=b[e]+sum;
      printf("\nsum=%d\n",sum);
	
  }	
    	
    	
  return 0;
  }
  
