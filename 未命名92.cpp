#include<stdio.h>
#include<math.h>
main()
{
	int h1,m1,h2,m2,t1,t2;
	printf("Input time one(hour, minute):");
    scanf("%d,%d",&h1,&m1);
	printf("Input time two(hour, minute):");
	scanf("%d,%d",&h2,&m2);
    if(h1>h2)
{ 
       if(m1<m2)
       {
	    t2=m1+60-m2;
        t1=h1-h2-1;
       }
      if(m1==m2);
      {
	  t2=m1-m2;
      t1=h1-h2;
      }
	   if(m1>m2) 
	  {
	  	t1=h1-h2;
	  	t2=m1-m2;
	  } 
}
    if(h1<h2)
{
	  if(m1>m2)
	  {
	  	t2=m2+60-m1;
	  	t1=h2-h1-1;
	  }
		if(m1==m2)
		{
			t2=m1-m2;
			t1=h2-h1;
		}
		if(m1<m2)
		{
			t1=h2-h1;
			t2=m2-m1;
		}
}
    if(h1==h2)
       {
       	t1=h1-h2;
       	t2=fabs(m1-m2);
	   }
	printf("%d hour %d minute\n",t1,t2);
}
