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
		printf("请选择你需要的服务：\n1.删除学号\n2.插入学号\n3.打印出成绩\n4.退出程序\n");
	    scanf("%d",&e);
	    switch(e)
	    {
	    	case 1:while(1)
	    {
		    printf("请输入要删除的学号：");
	        scanf("%d",&x);
	        if(x==0)
	        {
	    	    break;
		    }
	        p=del(p,x);
	    }break;
	        case 2:for(i=0;i<H;i++)
	    {
		    printf("请输入要插入的学号：");
	        scanf("%d",&stu1[i].num);
	        if(stu1[i].num==0)
	        {
		        break;
	        }
	        printf("请输入他的成绩：");
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
	printf("请输入学号：");
	scanf("%d",&p1->num);
	printf("请输入成绩：");
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
		printf("请输入学号：");
		scanf("%d",&p1->num);
		printf("请输入成绩：");
		scanf("%d",&p1->score);
	 } 
	 p2->next=NULL;
	 return head;
}

int print(struct student *head)
{
	int x;
	printf("这里共有%d个成绩\n",n);
    x=n;
	if(head)
	{
		do
	{
		
		printf("%d号同学的成绩为%d\n",head->num,head->score);
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
		printf("\n这个链表为空\n");
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
		printf("\n成功删除%d号同学的成绩！\n",num);
		n=n-1;
	}
	else
	{
		printf("%d并没被找到\n",num);
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

