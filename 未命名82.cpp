#include <stdio.h>
#include <string.h>
int main()
{
	printf("Please enter a string:\n");
	char weekDay[7][10] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };
char *p[7];
char a[10];
gets(a);
char *q;
int k;
int i;
int j;
int flag = 0;
q = a;
for (i = 0; i < 6; i++)
{
	k = 0;
	p[i] = &weekDay[i][0];
	for (j = 0; j < strlen(weekDay[i]); j++)
		if (*p[i] == *q) { p[i] = p[i] + 1; q++; k++; }
	if (k == strlen(weekDay[i])) { printf("%s is %d\n",a, i); flag = 1; }
}
if (flag == 0)  printf("Not found!\n");


}
