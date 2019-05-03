 #include<stdio.h>
   void main()
   {
       char a;
	   printf("Input simple:\n");
	   scanf("%c",&a);
	   if (a>=48&&a<=57)
		   printf("It is a digit character.\n");
		   else if (a>=65&&a<=90)
		   printf ("It is an English character.\n");
		   else if (a>=97&&a<=122)
          printf ("It is an English character.\n");
		   else printf ("It is other character.\n");
}
