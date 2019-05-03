#include <stdio.h> 
int GetApple(int a[], int height, int n);
int main()
{
  int a[10],b,c,i,n;
  c=0;
  for (i=0;i<10;i++)
      {	scanf("%d",&a[i]);}
	scanf("%d",&b);	
	n=GetApple(a, b, c);
	printf("%d\n",n);
	return 0;
}
 int GetApple(int a[], int height, int n)
 {
 	int i;
 	for(i=0;i<10;i++)
 	 {  if(a[i]<=height+30)
 	   	{ n=n+1;}
	  }
 	return n;
 }
