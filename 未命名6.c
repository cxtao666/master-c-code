#include <stdio.h> 
int main()
{
	int a,b,i;
	i=0; 
	printf("Please enter the number:\n");
	scanf( "%d",&a);
	if(a>0)
	{
	for (b=1;b<a;i++)
	{ 
	  b=10*b;
	}
	printf("%d: %d bits\n",a,i);
	} 
	else if(a<0)
	{ for (b=-1;b>a;i++)
	   {b=10*b;}
		printf("%d: %d bits\n",a,i);
	}
    else  printf("0; 1 bits\n");
   return 0
   

}
