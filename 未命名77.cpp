#include <stdio.h>
int CountRepeatNum(int count[], int n);
int main()
{
   long a;
   printf("Input n:\n");
   scanf("%ld",&a);
   int b[100];
	if(CountRepeatNum(b,a)==-1) printf("No repeated digit!\n");
	else printf("Repeated digit!\n");
	return 0;
}
int CountRepeatNum(int count[], int n)
{
   int i=0,j,k,flag=0,a;
   while (n>0)
   {
   	count[i]=n%10;
   	i++;
   	n=n/10;
   }
	for(j=0;j<i;j++) 
	for(k=j+1;k<i;k++) 
	{if(count[j]==count[k]) 
	 {
	flag=1;a=count[k];break;}}
	  if(flag==1) return a;
	   else  return -1;
	
}
