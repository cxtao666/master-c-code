#include <stdio.h>
int main()
{
	int n,b=0,c=0,d=0;int max=0;int i;
	 char *p,*q,*e;
	  int f[3];
printf("Input the number of electorates:");	
	scanf("%d",&n);
	char a[n][5] ;
	for(i=0;i<n;i++)
{
	    printf("Input vote %d:",i+1);
	   scanf("%s",a[i]);
	   if(a[i][0]=='t') {b++;p=a[i];}
	    if(a[i][0]== 'j' ) {c++;q=a[i];}
	    if(a[i][0]== 'r') {d++;e=a[i] ;}
}
    printf("Election results:\n");
   printf("%s:%d\n",p,b);
   printf("%s:%d\n",q,c);           
   printf("%s:%d\n",e,d);
     f[0]=b;f[1]=c;f[2]=d;
    for(i=0;i<3;i++)
    {if(f[0]<=f[i]) if(f[i]>max) max=f[i];} 
    if(max==b) printf("%s wins\n",p);
    if(max==c)  printf("%s wins\n",q);
    if(max==d)   printf("%s wins\n",e);
    return 0;
}
