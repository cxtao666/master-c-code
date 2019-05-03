#include <stdio.h>
#include <stdlib.h>
struct NODE
{
    int num;
    struct NODE *next;
};
 
int main( )
{ 
    struct NODE *p,*q,*r;
    int sum=0;
    p=(struct NODE *)malloc(sizeof(struct NODE));
    q=(struct NODE *)malloc(sizeof(struct NODE));
    r=(struct NODE *)malloc(sizeof(struct NODE));
    p->num=1;
    q->num=2;
    r->num=3;
    p->next=q;
   q->next=r;
    r->next=NULL;
   sum+=q->next->num;
   sum+=p->num;
   printf("%d\n",sum);
   return 0;
}




