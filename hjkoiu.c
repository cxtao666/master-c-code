#include <stdio.h>  
void main()
{
	int a,b,c;
	float d,e;
	printf ("Please input n:\n");
	scanf("%d",&a);
    b=a/100;
	c=a%100;
    printf("%d,%d\n",b,c);
    printf("sum=%d,sub=%d,multi=%d\n",c+b,b-c,c*b);
	d=b;
	e=c;
	if (e==0)  printf("The second operator is zero!\n");
	else   printf("dev=%.2f,mod=%d\n",d/e,b%c) ;

}