#include <stdio.h> 
void Seperate(int a[], int n); 
int main()
{  int n,i;
  printf("Input n:");	
	scanf("%d",&n);
	printf("Input numbers:");
	 int a[n];
	for(i=0;i<n;i++)
	   scanf("%d",&a[i]) ;
	Seperate(a,n);

}
void Seperate(int a[], int n)
{    int q=0,s=0,i;
	int *p1[n];
	int *p2[n];
    for(i=0;i<n;i++)
	  {
	  if(a[i]%2==1) {p1[q]=&a[i] ; q++;}
	   if(a[i]%2==0) {p2[s]=&a[i] ;s++;}	
} 
    for(i=0;i<q;i++) 
	if(i==0) printf("%d",*p1[0]);
	  else printf(",%d",*p1[i]);
	  printf("\n");
	  for(i=0;i<s;i++) 
	if(i==0) printf("%d",*p2[0]);
	  else printf(",%d",*p2[i]);
}
