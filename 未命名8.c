#include  <stdio.h>
  int main()
  { 
      int sum = 0, m;
      do{
          printf("Input m:\n");
          scanf("%d", &m);
          sum = sum + m;
          printf("sum = %d\n", sum);
      }while (m != 0);
      return 0;
  }
