#include<stdio.h>
int main()
{   char c;
	char *a;
	char *b;
	 b=&c;
	a=b;
	*a='a';
	printf("%c",*b);
}
