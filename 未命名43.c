#include <stdio.h> 
double  Calculate (double x,double y);
int main()
{
	double  a,b,c;
	printf("Input two doubles:\n");
	scanf("%lf%lf",&a,&b);
	c=Calculate(a,b);
	printf("1/((1/x+1/y)/2) = %0.3f\n",c);
	return 0;
}
double Calculate(double x,double y)
{
   double a;
   a=1/((1/x+1/y)/2) ;	
	return a;
}
