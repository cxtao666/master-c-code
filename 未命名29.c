#include <stdio.h>
int CountDigit(int number,int digit);
int main()
{
	int m,n;
	printf("Input m,n:\n");
	scanf("%d,%d",&m,&n);
    CountDigit(m,n);
	return 0;
}
int CountDigit(int number,int digit)
{
	int n,c,g,b,h;
   c=0;
   n=10;
   if(number<n)
   {
     if(number==digit)
     c++;
   }
   while (n<number)
   { 
    b=number%n;
    g=b*10/n;
    if(g==digit)
     c++;
   	 n=n*10;
   } 
   h=number*10/n;
   if(h==digit)
   c++;
printf("%d",c);
return 0;	
}
