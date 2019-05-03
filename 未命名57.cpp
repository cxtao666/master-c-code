#include <stdio.h>

float fun(int n)
{  int i;
float a;
   a=0;
 if(n%2==0)   { for(i=2;i<=n;i+=2) a=a+1.0/i;}
 if(n%2==1)  { for(i=1;i<=n;i+=2)  a=a+1.0/i; }
  return a;
}

//声明函数
void NONO ();

int main( )
{
	int n;
	while (1)
	{
		scanf("%d",&n);
		if(n>1)
			break;
	}
	printf("%f",fun(n));
	NONO ();
	return 0;
}


void NONO ()
{/* 本函数用于打开文件，输入数据，调用函数，输出数据，关闭文件。 */
	int s[5];
	FILE *rf, *wf ;
	int i ;

	rf = fopen("in.dat","r") ;
	wf = fopen("out.dat","w") ;
	for(i = 0 ; i < 5 ; i++) {
		fscanf(rf, "%d", &s[i]) ;
	}
	for(i = 0 ; i < 5 ; i++) {
		fprintf(wf, "%f\n",fun(s[i])) ;
	}
	fclose(rf) ;
	fclose(wf) ;
}

