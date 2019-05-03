#include <stdio.h>
long Fact(int n);
int main()
{
	int m, n, a, b, c;
	for (a=0;a<10;a++)
	{
		for (b=1;b<10;b++)
		{
			for (c=1;c<10;c++)
			{
				n = Fact(a) + Fact(b) + Fact(c);
				m = a * 100 + b * 10 + c;
				if (m == n)
				{
					printf("%d\n", m);
				}
			}
		}
	}
	return 0;
}

long Fact(int n)
{
	int  i;
	long result = 1;
	for (i=1;i<=n;i++)
	{
		result *= i;
	}
	return (result);
}

