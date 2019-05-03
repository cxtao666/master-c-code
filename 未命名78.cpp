#include <stdio.h>
int IsCancel(int a[], int n, int k);
int main()
{   int n,k,i;
	printf("Input n,k:\n");
	scanf("%d,%d",&n,&k);
	int a[n];
	for(i=0;i<n;i++)
	scanf("%d",&a[i]) ;
	if(IsCancel(a, n, k)==1) printf("YES");
	else if(IsCancel(a, n, k)==0) printf("NO");
	return 0;
}
int IsCancel(int a[], int n, int k)
{   int b=0,i;
	for(i=0;i<n;i++)  if(a[i]<0)b++;
	 if(b>=k) return 0;
	   else return 1;
	
	
}
