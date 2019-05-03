#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define N sizeof(struct student )
#define H 30
int print(struct student *head);
struct student *sequence(struct student *head);
struct student
{
	int num;
	int score;
	struct student *next;
};
struct student *creat();
struct student *del(struct student *head,int num);
struct student *insert(struct student *head,struct student *stu1);
int n;
int main()
{
	struct student *stu,*p;
	struct student stu1[H];
	int x;
	int i,e=0;
	stu=creat();
	p=stu;
	p=sequence(p);
	
	do
	{
		printf("��ѡ������Ҫ�ķ���\n1.ɾ��ѧ��\n2.����ѧ��\n3.��ӡ���ɼ�\n4.�˳�����\n");
	    scanf("%d",&e);
	    switch(e)
	    {
	    	case 1:while(1)
	    {
		    printf("������Ҫɾ����ѧ�ţ�");
	        scanf("%d",&x);
	        if(x==0)
	        {
	    	    break;
		    }
	        p=del(p,x);
	    }break;
	        case 2:for(i=0;i<H;i++)
	    {
		    printf("������Ҫ�����ѧ�ţ�");
	        scanf("%d",&stu1[i].num);
	        if(stu1[i].num==0)
	        {
		        break;
	        }
	        printf("���������ĳɼ���");
	        scanf("%d",&stu1[i].score);
	        p=insert(p,&stu1[i]);
	    }break;
	        case 3:print(p);break;
	        case 4:break;
		}
	}while(e<4);
	
	printf("\n\n");
	system("pause");
}

struct student *creat()
{
	struct student *head;
	struct student *p1,*p2;
	p1=p2=(struct student *)malloc(N);
	printf("������ѧ�ţ�");
	scanf("%d",&p1->num);
	printf("������ɼ���");
	scanf("%d",&p1->score);
	n=0;
	head=NULL;
	while(p1->num)
	{
		n++;
		if(n==1)
		{
			head=p1;
		}
		else
		{
			p2->next=p1;
		}
		p2=p1;
		p1=(struct student *)malloc(N);
		printf("������ѧ�ţ�");
		scanf("%d",&p1->num);
		printf("������ɼ���");
		scanf("%d",&p1->score);
	 } 
	 p2->next=NULL;
	 return head;
}

int print(struct student *head)
{
	int x;
	printf("���ﹲ��%d���ɼ�\n",n);
    x=n;
	if(head)
	{
		do
	{
		
		printf("%d��ͬѧ�ĳɼ�Ϊ%d\n",head->num,head->score);
		head=head->next;
		x--;
		if(x==0)
		{
			break;
		}
	}
	while(head);
	}
 } 

struct student *insert(struct student *head,struct student *stu1)
{
	struct student *p1,*p2,*p0,*p3;
	p1=head;
	p0=stu1;
	p3=p0;
	if(NULL==head)
	{
		head=p0;
		p0->next=NULL;
	}
	else
	{
		while((p0->num>p1->num)&&(p1->next!=NULL))
		{
			p2=p1;
			p1=p1->next;
		}
		if(p0->num<=p1->num)
		{
			if(head==p1)
			{
				head=p0;
			}
			else
			{
				p2->next=p0;
			}
			p0->next=p1;
		}
		else
		{
			p1->next=p0;
			p0->next=NULL;
		}
	}
	n=n+1;
	return head;
}

struct student *del(struct student *head,int num)
{
	struct student *p1,*p2;
	if(NULL==head)
	{
		printf("\n�������Ϊ��\n");
		goto end;
	}
	p1=head;
	while(p1->num!=num&&p1->next!=NULL)
	{
		p2=p1;
		p1=p1->next;
	}
	if(num==p1->num)
	{
		if(p1==head)
		{
			head=p1->next;
		}
		else
		{
			p2->next=p1->next;
		}
		printf("\n�ɹ�ɾ��%d��ͬѧ�ĳɼ���\n",num);
		n=n-1;
	}
	else
	{
		printf("%d��û���ҵ�\n",num);
	}
end:return head;
}

struct student *sequence(struct student *head)
{
	struct student *p1,*p2,*p3;
	int temp,temp1;
	p1=head;
	if(head==NULL)
	{
		goto end;
	}
	else
	{
		for(p1->num;p1->next!=NULL;p1=p1->next)
		{
			for(p2=p1->next;p2!=NULL;p2=p2->next)
			{
				if(p1->num>p2->num)
				{
					temp=p1->num;
					temp1=p1->score;
					p1->num=p2->num;
					p1->score=p2->score;
					p2->num=temp;
					p2->score=temp1;
				}
			}
		}
	}
	end: return head;
}

