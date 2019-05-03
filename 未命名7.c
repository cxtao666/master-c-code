#include  <stdio.h>
  int main()
  { 
      int sum = 0, m,i=0; 
	 
		  printf("Input m:\n");
          scanf("%d", &m);
         if(m!=0)  {
		 while (i<=m)
		   {
		   sum = sum + i;
		   i++;
          }
           printf("sum = %d\n", sum);}
      return 0;
  }
