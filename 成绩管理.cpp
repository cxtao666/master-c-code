#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
typedef struct student {
	char studentID[11];
	char name[10] ;
	char score[6][4] ;
	int total;
} STUDENT;
struct link {
	STUDENT date ;
	struct link *next;
	struct link *prev;
};
int m,n;
void input(); //录入每个学生的学号.姓名和各科考试成绩
void course(struct link*ps,int n,int m); //计算每门课程的总分和平均分
void stdudent(struct link*ps,int n,int m); //计算每个学生的总分和平均分
void descending(struct link*ps,int n,int m);//按每个学生的总分由高到低排出名次表
void ascending(struct link*ps,int n,int m  );//按每个学生的总分由低到高排出名次表
void number(struct link*ps,int n,int m ) ;//按学号由小到大排出成绩表
void addwithremove (struct link*ps,int n,int m ) ;//添加和删除学生信息
void searchnumber (struct link*ps,int n,int m);//按学号查询学生排名及其考试成绩
void searchname (struct link*ps,int n,int m) ;//按姓名查询学生排名及其考试成绩
void statistic(struct link*ps,int n,int m) ;//统计不同类别内学生人数和情况
void list (struct link*ps,int n,int m  );//输出每个学生的信息
void wfile(struct link*ps,int n,int m);// 将学生信息写入文件
void rfile (); //将信息从文件中读出
void exits();//退出
void help () ; //帮助
void freememory(struct link*ps);//归还空间
void add (struct link*ps,int n,int m ); //添加学生信息
void remove(struct link*ps,int n,int m ); // 删除学生信息
int main() {
	int a,n=0;
	printf("       欢迎来到学生成绩管理系统！\n");
	printf("将为您提供以下服务\n");
	printf("1.录入学生信息\n");
	printf("2.从文件中读取学生信息\n");
	printf("3.查看功能\n");
	printf("0.退出\n");
	printf("请输入您的需求\n");
	scanf("%d",&a);
	while (a<0||a>3) {
		printf("您的输入有误，请重新选择。\n");
		scanf(" %d",&a);
	}
	while (a==3) {
		help()  ;
		printf("请您继续录入信息");
		scanf("%d",&a);
	}
	if(a==1) input();
	if(a==2)  rfile ()  ;
	if(a==0)  exits() ;
	return 0;
}
void exits() {
	exit(0);
}
void stdudent(struct link*ps,int n,int m) {
	int to;
	int i,j;
	float s;
	s=m;
	to=0;
	for(j=0; j<n; j++) {
		to=0;
		for(i=0; i<m; i++)
			to=(ps->date.score[i][0]-48)*10+(ps->date.score[i][1]-48)+to;
		printf("%d",to);
		printf("  %0.2f\n",to/s);
		ps=ps->next;
	}
	return ;
}
void input() {
	int	i=0,j;
	int next=1;
	int choice;
	char a;
	printf("请输入人数");
	scanf("%d",&n);
	printf("请输入多少门成绩");
	scanf("%d",&m) ;
	struct link *head=NULL;
	struct link  *p=NULL,*q=NULL;
	struct link *l;
	head=(struct link *)malloc(sizeof(struct link));
	p=(struct link *)malloc(sizeof(struct link));
	if(p==NULL) {
		printf("NO enough memory!\n");
		exit(1);
	}
	if( head==NULL) {
		printf("NO enough memory!\n");
		exit(1);
	}
	if(p==NULL)  exit(0);
	head->next=p;
	l=head->next;
	p->prev=head;
	while(i<n ) {
		printf("请输入学号");
		scanf("%s",p->date.studentID);
		printf("请输入姓名");
		scanf("%s",p->date.name);
		printf("请输入各科成绩");
		for(j=0; j<m; j++) {
			scanf(" %s",p->date.score[j]);
		}
		q=(struct link *)malloc(sizeof(struct link));
		if(q==NULL) {
			printf("NO enough memory!\n");
			exit(1);
		}
		q->prev=p;
		p->next=q;
		p=q;
		i++;
	}
	p->prev->next=NULL;
	printf("想要将信息保存到文件中吗？请输入Y或N\n");
	scanf(" %c",&a);
	if(a=='Y') wfile( l ,n,m);
	printf("请选择您接下来的操作\n") ;
	help();
	while(next==1) {
		scanf (" %d",&choice );
		if(choice==2)   course(l,n,m)  ;
		else if(choice==3)  stdudent(l,n,m) ;
		else if(choice==4)    descending(l, n, m) ;
		else if(choice==5)    ascending(l, n, m)  ;
		else if(choice==6)    number(l, n, m);
		else if(choice==7)    addwithremove(l, n, m);
		else if(choice==8)   searchnumber(l, n, m);
		else if(choice==9)     searchname (l, n, m) ;
		else if(choice==10)     statistic(l, n, m);
		else if(choice==11)   list(l, n, m);
		else if(choice==12)   rfile ();
		else if(choice==1)  input() ;
		else if(choice==13) wfile(l,n,m);
		else exits();
		printf("请问您还需要其它操作吗,按Y或N继续\n");
		scanf(" %c",&a);
		if(a=='Y')  {
			next=1;
			printf("请继续选择操作");
		} else next=0;
		l=head->next;
	}
	freememory(l) ;
	free(head);
	printf("       感谢您的使用");
	return;
}
void course(struct link*ps,int n,int m) {
	struct link* q=ps;
	int to;
	int i,j;
	float s;
	s=n;
	for(j=0; j<m; j++) {
		to=0;
		for(i=0; i<n; i++) {
			to=(ps->date.score[j][0]-48)*10+(ps->date.score[j][1]-48)+to;
			ps=ps->next;
		}
		printf("%d",to);
		printf("  %0.2f\n",to/s);
		ps=q;
	}
	return ;
}

void wfile (struct link*ps,int n,int m) {
	struct link *q;
	int i,j;
	FILE *p;
	char path[100];
	printf("请输入文件路径\n") ;
	scanf("%s",path);
	p=fopen(path,"a+");
	if(p==NULL)  p=fopen("D:\\information.txt","w");
	if(p==NULL)  p=fopen("D:\\information.txt","a");
	while(ps!=NULL) {
		fprintf(p,"%s  %s",ps->date.studentID,ps->date.name);
		for(j=0; j<m; j++)
			fprintf(p,"  %s",ps->date.score[j]);
		fprintf(p,"-1");
		ps=ps->next;
	}
	fclose(p);
}
void help() {
	printf("0.退出\n");
	printf("1.录入每个学生的学号.姓名和各科考试成绩\n");
	printf("2.计算每门课程的总分和平均分\n");
	printf("3.计算每个学生的总分和平均分\n") ;
	printf("4.按每个学生的总分由高到低排出名次表\n");
	printf("5.按每个学生的总分由低到高排出名次表\n");
	printf("6.按学号由小到大排出成绩表\n");
	printf("7.添加学生信息或删除学生信息\n");
	printf("8.按学号查询学生排名及其考试成绩\n");
	printf("9.按姓名查询学生排名及其考试成绩\n");
	printf("10.统计不同类别内学生人数和情况\n");
	printf("11.输出每个学生的信息\n");
	printf("12.从文件中读出每个学生的记录信息并显示\n");
	printf("13.将学生信息写入文件\n");
	return ;
}
void rfile () {
	int b;
	char a;
	int i=0;
	int next=1;
	int choice;
	char *p;
	char e;
	int k;
	char ch;
	char path[100];
	FILE *p1;
	struct link *p2;
	struct link *p3;
	struct link *l;
	struct link *p4;
	struct link *head;
	printf("请输入文件路径\n") ;
	scanf("%s",path);
	p1=fopen(path,"r");
	if(p1==NULL) {
		printf("对不起该路径下不存在该文件，是否输入信息，按Y或N继续\n");
		scanf(" %c",&a);
		if(a=='Y')  input();
		else 	exits();
	} else {
		printf("是否格式化输出，按Y或N继续\n");
		scanf(" %c",&e);
		if(e=='N') {
			while((ch=fgetc(p1))!=EOF) {
				if(ch<0||(ch>='0'&&ch<='9')||(ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
					printf("%c",ch);
			}
			printf("\n请继续您初始菜单的选择:") ;
			scanf("%d",&b) ;
			if(b==1) input();
			if(b==2)  rfile ()  ;
			if(b==0)  exits() ;
		}
		if(e=='Y') {
			printf("请输入文本中学生人数");
			scanf("%d",&n);
			printf("请输入考生科目数");
			scanf("%d",&m);
			STUDENT str[n];
			for(i=0; i<n; i++) {
				fscanf(p1,"%s",str[i].studentID) ;
				fscanf(p1,"%s",str[i].name);
				for(k=0; k<m; k++)
					fscanf(p1,"%s",str[i].score[k]);
			}
			for(i=0; i<n; i++) {
				printf(" %s %s",str[i].studentID,str[i].name);
				for(k=0; k<m; k++)  printf(" %s",str[i].score[k]);
				printf("\n");
			}
			head=(struct link *)malloc(sizeof(struct link));
			fclose(p1);
			if(head==NULL) {
				printf("NO enough memory!\n");
				exit(1);
			}
			p2=(struct link *)malloc(sizeof(struct link));
			head->next=p2;
			if(p2==NULL) {
			
				printf("NO enough memory!\n");
				exit(1);
			}
			l=head->next;
			for (i=0; i<n; i++) {
				p3=(struct link *)malloc(sizeof(struct link));
				if(p3==NULL) {
					printf("NO enough memory!\n");
					exit(1);
				}
				strcpy(p2->date.name,str[i].name);
				strcpy(p2->date.studentID,str[i].studentID);
				for(k=0; k<m; k++)
					strcpy(p2->date.score[k],str[i].score[k]);
				p3->prev=p2;
				p2->next=p3;
				p2=p3;
			}
			p2->prev->next=NULL;
			free(p3);
			printf("\n请选择您接下来的操作\n") ;
			help();
			while(next==1) {
				scanf (" %d",&choice );
				if(choice==2)   course(l,n,m)  ;
				else if(choice==3)  stdudent(l,n,m) ;
				else if(choice==4)    descending(l,n,m) ;
				else if(choice==5)    ascending(l,n,m)  ;
				else if(choice==6)    number(l,n,m);
				else if(choice==7)    addwithremove(l,n,m);
				else if(choice==8)   searchnumber (l,n,m) ;
				else if(choice==9)     searchname (l,n,m) ;
				else if(choice==10)     statistic(l,n,m);
				else if(choice==11)   list(l,n,m);
				else if(choice==12)   rfile ();
				else if(choice==1)  input() ;
				else if(choice==13)  wfile(l,n,m);
				else exits();
				l=head->next;
				printf("请问您还需要其它操作吗,按Y或N继续\n");
				scanf(" %c",&a);
				if(a=='Y')  {
					next=1;
					printf("请继续选择操作");
				} else next=0;
			}
		}
	}
	freememory(l) ;
	free(head);
	printf("       感谢您的使用");
	return ;
}
void descending(struct link*ps,int n,int m ) {
	STUDENT  a[n];
	char name1[10];
	int to;
	int i,j;
	int temp;
	float s;
	s=m;
	to=0;
	for(j=0; j<n; j++) {
		to=0;
		for(i=0; i<m; i++)
			to=(ps->date.score[i][0]-48)*10+(ps->date.score[i][1]-48)+to;//算出单个人的总分
		a[j].total=to;
		strcpy(a[j].name,ps->date.name);
		ps=ps->next;
	}
	for(j=0; j<n; j++)
		for(i=j+1; i<n; i++)
			if(a[i].total>a[j].total) {
				temp=a[j].total;
				a[j].total=a[i].total;
				a[i].total=temp;
				strcpy(name1,a[j].name);
				strcpy(a[j].name,a[i].name) ;
				strcpy(a[i].name,name1);
			}
	for(i=0; i<n; i++) printf("第%d名：%s 总分：%d\n",i+1,a[i].name,a[i].total);
	return ;
}
void ascending(struct link*ps,int n,int m  ) {
	STUDENT  a[n];
	char name1[10];
	int to;
	int i,j;
	int temp;
	float s;
	s=m;
	to=0;
	for(j=0; j<n; j++) {
		to=0;
		for(i=0; i<m; i++)
			to=(ps->date.score[i][0]-48)*10+(ps->date.score[i][1]-48)+to;//算出单个人的总分
		a[j].total=to;
		strcpy(a[j].name,ps->date.name);
		ps=ps->next;
	}
	for(j=0; j<n; j++)
		for(i=j+1; i<n; i++)
			if(a[i].total<a[j].total) {
				temp=a[j].total;
				a[j].total=a[i].total;
				a[i].total=temp;
				strcpy(name1,a[j].name);
				strcpy(a[j].name,a[i].name) ;
				strcpy(a[i].name,name1);
			}
	for(i=0; i<n; i++) printf("第%d名：%s 总分：%d\n",n--,a[i].name,a[i].total);
	return ;
}
void list (struct link*ps,int n,int m ) {
	int j;
	while(ps!=NULL) {
		printf("学号：%s 姓名： %s",ps->date.studentID,ps->date.name);
		printf("成绩：");
		for(j=0; j<m; j++)
			printf("  %s",ps->date.score[j]);
		printf("\n") ;
		ps =ps->next;
	}
	return ;
}
void number(struct link*ps,int n,int m ) {
	int i=0;
	int j,k;
	struct link*p;
	struct link*l=ps;
	struct link *p1[n];
	struct link *h;
	h=  (struct link *)malloc(sizeof(struct link));
	strcpy( h->date.studentID,"9999999999");
	for(ps->date.studentID; ps!=NULL; ps=ps->next) {
		p1[i]=h;
		for( p=l; p!=NULL; p=p->next) {
			if(i==0) {
				p1[i]=ps;
				if( strcmp(ps->date.studentID,p->date.studentID)>=0) {
					if(strcmp(p1[i]->date.studentID,p->date.studentID)>0) {
						if(i==0)  p1[i]=p;

					}
				}
			}
			if(i>0) {
				if(strcmp(p1[i]->date.studentID,p->date.studentID)>0) {
					j=0;
					while(strcmp(p1[j]->date.studentID,p->date.studentID)<0)
						j++;
					if(j==i) p1[i]=p;
				}
			}
		}
		i++;
	}


	for(j=0; j<n; j++) {
		printf("学号：%s 姓名： %s",p1[j]->date.studentID,p1[j]->date.name);
		printf("  成绩:");
		for(k=0; k<m; k++)
			printf("  %s",p1[j]->date.score[k]);
		printf("\n") ;
	}
	return;
}
void searchnumber (struct link*ps,int n,int m) {
	int flag=0;
	int j;
	char a[11];
	printf("请输入您的学号\n") ;
	scanf("%s",a);
	while(ps!=NULL) {
		if(strcmp(ps->date.studentID,a)==0) {
			printf("学号：%s 姓名： %s",ps->date.studentID,ps->date.name);
			printf(" 成绩：");
			for(j=0; j<m; j++)
				printf(" %s",ps->date.score[j]);
			printf("\n") ;
			flag=1;
		}
		ps=ps->next;
	}
	if(flag==0) printf("对不起，您输入的学号未在列表中找到") ;
	return ;
}
void searchname (struct link*ps,int n,int m) {
	int flag=0;
	int j;
	char a[11];
	printf("请输入您要查询的姓名\n") ;
	scanf("%s",a);
	while(ps!=NULL) {
		if(strcmp(ps->date.name,a)==0) {
			printf("学号：%s 姓名： %s",ps->date.studentID,ps->date.name);
			printf(" 成绩：");
			for(j=0; j<m; j++)
				printf(" %s",ps->date.score[j]);
			printf("\n") ;
			flag=1;
		}
		ps=ps->next;
	}
	if(flag==0) printf("对不起，您输入的姓名未在列表中找到") ;
	return ;
}
void statistic(struct link*ps,int n,int m) {
	struct link*p;
	p=ps;
	int flag=0;
	int i;
	int j;
	int a[5]= {0,0,0,0,0};
	printf("请输入您要划分类别的科目\n") ;
	scanf("%d",&i) ;
	while(flag<n) {
		j=(ps->date.score[i-1][0]-48)*10+(ps->date.score[i-1][1]-48);
		if(j<60) a[0]++;
		if(j>=60&&j<70) a[1]++;
		if(j>=70&&j<80)  a[2]++;
		if(j>=80&&j<90)  a[3]++;
		if(j>=90&&j<=100)  a[4]++;
		ps =ps->next ;
		flag++;
	}
	ps=p;
	printf("优秀人数(90-100)有%d人\n",a[4]);
	while(ps!=NULL) {
		j=(ps->date.score[i-1][0]-48)*10+(ps->date.score[i-1][1]-48);
		if(j>=90&&j<=100)
			printf("%s  %s  %s\n",ps->date.studentID,ps->date.name,ps->date.score[i-1]);
		ps =ps->next ;
	}
	ps=p;
	printf("良好人数(80-89)有%d人\n",a[3]);
	while(ps!=NULL) {
		j=(ps->date.score[i-1][0]-48)*10+(ps->date.score[i-1][1]-48);
		if(j>=80&&j<90)
			printf("%s  %s  %s\n",ps->date.studentID,ps->date.name,ps->date.score[i-1]);
		ps =ps->next ;
	}
	ps=p;
	printf("中等人数(70-79)有%d人\n",a[2]);
	while(ps!=NULL) {
		j=(ps->date.score[i-1][0]-48)*10+(ps->date.score[i-1][1]-48);
		if(j>=70&&j<80)
			printf("%s  %s  %s\n",ps->date.studentID,ps->date.name,ps->date.score[i-1]);
		ps =ps->next ;
	}
	ps=p;
	printf("及格人数(60-69)有%d人\n",a[1]);
	while(ps!=NULL) {
		j=(ps->date.score[i-1][0]-48)*10+(ps->date.score[i-1][1]-48);
		if(j>=60&&j<70)
			printf("%s  %s  %s\n",ps->date.studentID,ps->date.name,ps->date.score[i-1]);
		ps =ps->next ;
	}
	ps=p;
	printf("不及格人数(<60)有%d人\n",a[0]);
	flag=0;
	while(flag<n) {
		j=(ps->date.score[i-1][0]-48)*10+(ps->date.score[i-1][1]-48);
		if(j<60)
			printf("%s  %s  %s\n",ps->date.studentID,ps->date.name,ps->date.score[i-1]);
		ps =ps->next ;
		flag++;
	}
	return;
}
void addwithremove (struct link*ps,int n,int m ) {
	int a;
	printf("请输入你要选择的操作\n1.添加一个学生的信息\n2.删除一个学生的信息\n");
	scanf("%d",&a);
	if(a==1)  add(ps,n,m);
	if(a==2)  remove (ps,n,m);
	return;
}
void add (struct link*ps,int n,int m ) {
	int i,j;
	struct link*p;
	struct link*q;
	do {
		printf("请输入您要插入的学生的位置");
		scanf("%d",&i);
	} while(i>n+1);

	if(i>1&&i<n+1) {
		n++;
		int flag=1;
		while(flag<i-1) {
			ps=ps->next;
			flag++;
		}
		p=(struct link*)malloc(sizeof(struct link));
		printf("请输入学号");
		scanf("%s",p->date.studentID);
		printf("请输入姓名");
		scanf("%s",p->date.name);
		printf("请输入各科成绩");
		for(j=0; j<m; j++) {
			scanf(" %s",p->date.score[j]);
		}
		p->prev=ps;
		p->next=ps->next;
		ps->next->prev=p;
		ps->next=p;
	}
	if(i==1) {
		n++;
		p=(struct link*)malloc(sizeof(struct link));
		p->prev=ps->prev;
		ps->prev->next=p;
		ps->prev=p;
		p->next=ps;
		printf("请输入学号");
		scanf("%s",p->date.studentID);
		printf("请输入姓名");
		scanf("%s",p->date.name);
		printf("请输入各科成绩");
		for(j=0; j<m; j++) {
			scanf(" %s",p->date.score[j]);
		}
	}
	if(i==n+1) {
		int flag=1;
		while(flag<i-1) {
			ps=ps->next;
			flag++;
		}
		n++;
		p=(struct link*)malloc(sizeof(struct link));
		ps->next=p;
		p->prev=ps;
		p->next=NULL;
		printf("请输入学号");
		scanf("%s",p->date.studentID);
		printf("请输入姓名");
		scanf("%s",p->date.name);
		printf("请输入各科成绩");
		for(j=0; j<m; j++) {
			scanf(" %s",p->date.score[j]);
		}
	}
	return ;
}
void remove(struct link*ps,int n,int m ) {
	int flag =0;
	int a;
	char b;
	printf("请输入要删除的学生信息\n1.姓名    2.学号\n");
	scanf(" %d",&a);
	if(a==1) {
		searchname(ps,n,m);
		char a[11];
		printf("\n请确认您要删除的姓名\n") ;
		scanf("%s",a);
		while(ps!=NULL) {
			if(strcmp(ps->date.name,a)==0) {
				printf("该学生信息已被删除\n");
				ps->prev->next=ps->next;
				ps->next->prev=ps->prev;
				flag=1;
			}
			ps=ps->next;
		}
		if(flag==0) printf("对不起，该学生信息未被找到");
	}

	if(a==2) {
		char a[11];
		searchnumber(ps,n,m);
		printf("\n请确认您要删除的学号\n") ;
		scanf("%s",a);
		while(ps!=NULL) {
			if(strcmp(ps->date.name,a)==0) {
				printf("该学生信息已被删除\n");
				flag=1;
				ps->prev->next=ps->next;
				ps->next->prev=ps->prev;
			}
			ps=ps->next;
		}
		if(flag==0) printf("对不起，该学生信息未被找到");
	}
	return ;
}
void freememory(struct link*ps) {
	while(ps!=NULL) {
		ps =ps->next	;
		free(ps);
	}
	return ;
}
