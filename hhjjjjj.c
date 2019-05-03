#include <stdio.h>
void main()
{  int a;
   if ( scanf("%d",&a)==1 )
   { 
	 if (a>0)
      {   
         if(0==a%4)
     {
       if (0==a%400)
    
     printf ("Yes\n");

    
 else  if (0==a%100)
   printf("No\n"); 
 else   
  printf ("Yes\n");
 }



 else    
     printf("No\n");
    
   }
  else 
     printf("Input error!");
    
}
   else 
     printf("Input error!");
   
}