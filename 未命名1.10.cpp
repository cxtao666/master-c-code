#include  <stdio.h>
  int main()
  { 
      int sum = 0, m,i=0;
      printf("Input m:\n");
           scanf("%d", &m);
      do{
	
          sum = sum + i;
           i++;
      }while (i<=m);
      printf("sum = %d\n", sum);
      return 0;
  }
