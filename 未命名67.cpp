#include <stdio.h> 
#include<string.h>
void Caesar(char c[]);
int main()
{
	char c[100];
	printf("Input a string:");
	gets(c);
	Caesar(c);
	 puts(c);
	return 0;
}
void Caesar(char c[])
{  int i;
  for(i=0;i<strlen(c);i++)
	 if(c[i]>='a'&&c[i]<='w')  c[i]=c[i]+3;
	 else if(c[i]>='x'&&c[i]<='z')  c[i]=c[i]-23;
}
