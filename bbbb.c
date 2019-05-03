
#include<stdio.h>
void main()
{
	int a,b;
	char c;
	char str[80];
	gets (str) ;
    scanf ("%c",&c);
	for (b=a=0;str[a] != '\0';a++)
	{
	   if ( str[a] != c )
	   {  
		   str[b++] =str[a];
	   }
	  
	}
	   puts(str);
	   printf("%d %d",b,a);
		  

}
