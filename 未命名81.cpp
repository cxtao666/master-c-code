#include <stdio.h> 
#include <string.h>
int IsSubString(char a[], char b[]);
int main()
{    char a[80]; char b[80];
	printf( "Input the first string:");
	gets(a);
	 printf( "Input the second string:");
	gets(b);
    if(IsSubString(a, b)==1) printf("Yes\n");
	 else if(IsSubString(a, b)==0) printf( "No\n");
	return 0;
}
int IsSubString(char a[], char b[])
{
 char *p; int k=0,i,flag;
  p=b;
   for(i=0;i<strlen(a);i++)
{
	 	 if(a[i]==*p){
	  p++;k++;flag=1;}
 
   if(strlen(b)==k&&flag==1) return 1;
	 if(a[i]!=*p) flag=0;}
	 if(strlen(b)!=k) return 0;
	 
	 }
