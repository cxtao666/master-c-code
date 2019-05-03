#include <stdio.h> 
#include <string.h>
int main()
{
  printf( "Input M,T,U,F,D:");
  long int m	,t,u,f,d;
  scanf("%ld%ld%ld%ld%ld",&m,&t,&u,&f,&d) ;
  printf("Input conditions of road:");
  char T[t]	;
  int i,count=0;
   scanf("%s",T);
    long int realTime=m;
	i=0;
	while(realTime>0&&i<t){
		count++;
		switch(T[i++]){
			case 'u' :realTime-=(u+d);break;
			case 'f':realTime-=(f+f);break;
			case 'd':realTime-=(u+d);break;
			
		}
		if(realTime<0){  count--;
		}
	}
	printf("num=%ld\n",--count);
	
	return 0;	
	
	
	
}
