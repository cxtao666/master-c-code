#include <stdio.h>
void main()
{  int a,b,c;
    printf("Enter a date (mm/dd/yy):\n");
	scanf("%d%d%d",a,b,c);
    printf("You entered the date: %04d.%02d.%02d\n",c,b,a);
  }
