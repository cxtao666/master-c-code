#include<stdio.h> 
long Fact(int n);
int main()
{
	int a,b,c,m;
	for(m=100;m<1000;m++)
	  {
	  	 a=m/100;b=m/10-a*10;c=m%10;
	  	if(Fact(a)+Fact(b)+Fact(c)==m) printf("%d\n",m);
	  }
	return 0;
}
long Fact(int n)
{   int s=1,i;
   if(n==0)  return 1;	
	else if(n>=1) {
	for(i=1;i<=n;i++) 
  {	s=s*i; }
	return s;}
	
}
