
#include<stdio.h>
void main()
{
	int a,b,d;
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
	str[b]='\0';
	b=b-1;
		  d=str[b];
		   puts(str);
		   printf("%c\n",d);
		  

}
