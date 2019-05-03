#include <stdio.h> 
int main()
{
  int n,i,a,c,e;
  printf("Input n(n<=500):");
  scanf("%d",&n);
  for(i=2;i<=n;i++)
  {
  	for(a=2;a<=i;a++)
  	{
  	  if(i%a==0) 
      break;
	  }
     if(a==i) 
    {
    printf("%d",i);
    }
}
return 0;
}
 
