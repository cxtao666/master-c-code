char fun (char*)
#include <stdio.h>
char fun (char*)
int main() 
{
	char a;
	printf("Please input a capital:\n");
	scanf("%c",&a);
	fun(a);
	return 0;
}
char fun (char* b)
 {    
    int i,i;
 	for( i=0;i<=b-'A';i++)
    {	
	  for (j=0;j<=b-'A'-i;j++)
	 { printf(" ");	 }
	  printf("%c",'A'+i);
	 printf("\n");
	 return 0;
   }   
 }
	
	
	
	

