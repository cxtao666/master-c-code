#include <stdio.h> 
int swap(int*a,int*b);
int main()
{
  int a,b;	
	a=5;
	b=1;
   int *p;int*q;	
	p=&a;q=&b;
	 swap(p,q);
	printf("%d,%d",*p,*q);
	return 0;
}
int swap(int*a,int*b)
{
   int c;
   c=*a;
     *a=*b;	
	*b=c;
}
