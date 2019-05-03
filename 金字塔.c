#include <stdio.h>
char fun (char) ;
int main() 
{
	char a;
	printf("Please input a capital:\n");
	scanf("%c",&a);
	fun(a);
	return 0;
}
char fun (char b)
 {    
    int j,i,c,z,k;
    int d;
    d=b-'A';
 	for( i=0;i<=d;i++)
    {  c=i-1;	
	  for (j=0;j<=d-i;j++)
	 { printf(" ");	 }
	 for ( z=0;z<=i;z++ )
	 {  printf("%c",'A'+z); }
	 for ( k=0;k<i;k++)
	{ 
	printf("%c",'A'+c);
	  c=c-1;
 }   printf("\n");
   }
	return 0;
}
