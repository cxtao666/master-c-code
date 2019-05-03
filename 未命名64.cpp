#include <stdio.h>
#include <string.h> 
int CountRepeatStr(char str[], char *tag);
int main()
{   char str[80] ;
  char *a;
   int b;
   printf("Input a string:\n") ;	
	 gets(str) ;
	  b=CountRepeatStr(str, a);
	 printf("%c:%d\n",*a,b); 
	return 0;
}
 int CountRepeatStr(char str[], char *tag)
 {  int k=0; int max=0,i=0;
   for(i=0;i<strlen(str);i++)	
 	 {if(str[i] == str[i+1])  k++;
 	  if(str[i] != str[i+1])  
 	     {
		  if(k>=max) {max=k; k=0; tag=&str[i] ; }}}
 	 return max;
 }
