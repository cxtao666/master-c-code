#include <stdio.h> 
int main()
{    int a,i,b;
    i=0;b=0;
	printf("Please enter the number:");
	while (a!=-1)
  { 
   	 scanf("%d",&a);if(a!=-1){
		if(a%2==0)  {printf("%d:even\n",a);b=b+1;}
   	else if(a%2!=0) {printf("%d:odd\n",a);i=i+1;}}
}
   if(b+i==0) printf("over!\n");
	printf("The total number of odd is %d\n",b);
	printf("The total number of even is %d\n",i);
	return 0;
	
}
