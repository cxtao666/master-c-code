#include <stdio.h>
#include <stdlib.h>
#define N 1000
int main()
{   char b[100];
	FILE *p;
	FILE *q;
    int a ;
  p=fopen ("d:\\215.txt","wb");
  scanf("%d",&a);
	fprintf(p, "%d", a);
	fclose(p);
	q=fopen ("d:\\215.txt","r");
	fgets(b,N,q);
    puts(b);
	return 0;
	
}
