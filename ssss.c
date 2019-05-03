#include<stdio.h> 
int main()
{   int a,b,c;
    char ch ;
  a=0;
  b=0;
  c=0;
  printf("Please input a string end by #:\n");
  ch=getchar() ;
   while(ch!='#')
   {
   	 if(ch==' ')
   	 a++;
   	 else if (ch=='\n')
   	 b++;
   	 else c++;
   	ch=getchar();
   }
	printf("space: %d,newline: %d,others: %d\n",a,b,c);
	
 return 0;		
}