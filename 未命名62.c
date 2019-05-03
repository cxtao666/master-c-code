#include <stdio.h>
#include <string.h> 
int SearchString(char s[], char d[]);
int main()
{   char s[80] ;
   char d[80] ;
 	printf("Input a string:");
	gets(s);
	printf("Input another string:");
	gets(d);
	if(SearchString(s,d)==-1) printf("Not found!\n");
	  else printf("Searching results:%d\n",SearchString(s, d));
	return 0;	
}
int SearchString(char s[], char d[])
{  int k=0,i,j,t=0;
	for(j=0;j<strlen(s);j++ )
	  if(s[j]==d[0]&&s[j+strlen(d)]==' ') break;
	   t=j+1;
	 for(i=0;i<strlen(d) ;i++)
	    if( d[i]==s[j++]) k++;
	 if(k==strlen(d)) return t;
	  else return -1;
}
