#include <stdio.h>
int main()
{   float a;
   float s;
	printf("Input payment:");
	scanf("%f" ,&a);
	if(a/100<1) s=a;
	else if(a/100>=1&&a/100<2) s=0.95*a;
	else if(a/100==2&&a/100<5) s=0.92*a;
	else if(a/100>=5&&a/100<10) s=0.9*a;
	else  s=0.85*a;
	printf("price = %.1f\n",s);
	return 0;
}
