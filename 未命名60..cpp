#include <stdio.h>
#include<string.h>
int Myatoi(char str[]);
int main() 
{
  char a[8] ;
  printf("Input a string:");
  scanf("%7s",a);
  printf("%d\n", Myatoi(a ));
	return 0;
}
int Myatoi(char str[])
{  int k=0,i,n=1,z=0;int a[8];
  for(i=0;i<strlen(str);i++)	
	if(str[i]>='0'&&str[i]<='9')    { a[k]=(int)(str[i]-48);k=k+1;}
	for(i=0;i<=k-1;i++)
{
	z=a[i]*n+z;  z=z*10; }
	
	return z/10;
}
