#include <stdio.h> 
#include <string.h>
int main()
{  int i;
  char a[100];
  char *p;
   p=&a[2]; 
  printf("Input a sentence:");
   *p=getchar();
	 putchar(*p);
     p++;
    return 0;
}

