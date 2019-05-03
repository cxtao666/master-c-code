#include <stdio.h> 
int main()
{
   char a;
   int i=0;
   printf("Input your password:\n");
   while(i< 6)
 {
     scanf(" %c",&a);
    if(a>='0'&&a<='9')	
   {  i=i+1;
   printf("%c, you have enter %d-bits number\n",a,i);
   }
    else printf("error\n");
} 
	return 0;
	
	
}
