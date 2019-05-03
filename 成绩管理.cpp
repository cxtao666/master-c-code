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
void input(); //¼��ÿ��ѧ����ѧ��.�����͸��ƿ��Գɼ�
void course(struct link*ps,int n,int m); //����ÿ�ſγ̵��ֺܷ�ƽ����
void stdudent(struct link*ps,int n,int m); //����ÿ��ѧ�����ֺܷ�ƽ����
void descending(struct link*ps,int n,int m);//��ÿ��ѧ�����ܷ��ɸߵ����ų����α�
void ascending(struct link*ps,int n,int m  );//��ÿ��ѧ�����ܷ��ɵ͵����ų����α�
void number(struct link*ps,int n,int m ) ;//��ѧ����С�����ų��ɼ���
void addwithremove (struct link*ps,int n,int m ) ;//��Ӻ�ɾ��ѧ����Ϣ
void searchnumber (struct link*ps,int n,int m);//��ѧ�Ų�ѯѧ���������俼�Գɼ�
void searchname (struct link*ps,int n,int m) ;//��������ѯѧ���������俼�Գɼ�
void statistic(struct link*ps,int n,int m) ;//ͳ�Ʋ�ͬ�����ѧ�����������
void list (struct link*ps,int n,int m  );//���ÿ��ѧ������Ϣ
void wfile(struct link*ps,int n,int m);// ��ѧ����Ϣд���ļ�
void rfile (); //����Ϣ���ļ��ж���
void exits();//�˳�
void help () ; //����
void freememory(struct link*ps);//�黹�ռ�
void add (struct link*ps,int n,int m ); //���ѧ����Ϣ
void remove(struct link*ps,int n,int m ); // ɾ��ѧ����Ϣ
int main() {
	int a,n=0;
	printf("       ��ӭ����ѧ���ɼ�����ϵͳ��\n");
	printf("��Ϊ���ṩ���·���\n");
	printf("1.¼��ѧ����Ϣ\n");
	printf("2.���ļ��ж�ȡѧ����Ϣ\n");
	printf("3.�鿴����\n");
	printf("0.�˳�\n");
	printf("��������������\n");
	scanf("%d",&a);
	while (a<0||a>3) {
		printf("������������������ѡ��\n");
		scanf(" %d",&a);
	}
	while (a==3) {
		help()  ;
		printf("��������¼����Ϣ");
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
	printf("����������");
	scanf("%d",&n);
	printf("����������ųɼ�");
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
		printf("������ѧ��");
		scanf("%s",p->date.studentID);
		printf("����������");
		scanf("%s",p->date.name);
		printf("��������Ƴɼ�");
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
	printf("��Ҫ����Ϣ���浽�ļ�����������Y��N\n");
	scanf(" %c",&a);
	if(a=='Y') wfile( l ,n,m);
	printf("��ѡ�����������Ĳ���\n") ;
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
		printf("����������Ҫ����������,��Y��N����\n");
		scanf(" %c",&a);
		if(a=='Y')  {
			next=1;
			printf("�����ѡ�����");
		} else next=0;
		l=head->next;
	}
	freememory(l) ;
	free(head);
	printf("       ��л����ʹ��");
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
	printf("�������ļ�·��\n") ;
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
	printf("0.�˳�\n");
	printf("1.¼��ÿ��ѧ����ѧ��.�����͸��ƿ��Գɼ�\n");
	printf("2.����ÿ�ſγ̵��ֺܷ�ƽ����\n");
	printf("3.����ÿ��ѧ�����ֺܷ�ƽ����\n") ;
	printf("4.��ÿ��ѧ�����ܷ��ɸߵ����ų����α�\n");
	printf("5.��ÿ��ѧ�����ܷ��ɵ͵����ų����α�\n");
	printf("6.��ѧ����С�����ų��ɼ���\n");
	printf("7.���ѧ����Ϣ��ɾ��ѧ����Ϣ\n");
	printf("8.��ѧ�Ų�ѯѧ���������俼�Գɼ�\n");
	printf("9.��������ѯѧ���������俼�Գɼ�\n");
	printf("10.ͳ�Ʋ�ͬ�����ѧ�����������\n");
	printf("11.���ÿ��ѧ������Ϣ\n");
	printf("12.���ļ��ж���ÿ��ѧ���ļ�¼��Ϣ����ʾ\n");
	printf("13.��ѧ����Ϣд���ļ�\n");
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
	printf("�������ļ�·��\n") ;
	scanf("%s",path);
	p1=fopen(path,"r");
	if(p1==NULL) {
		printf("�Բ����·���²����ڸ��ļ����Ƿ�������Ϣ����Y��N����\n");
		scanf(" %c",&a);
		if(a=='Y')  input();
		else 	exits();
	} else {
		printf("�Ƿ��ʽ���������Y��N����\n");
		scanf(" %c",&e);
		if(e=='N') {
			while((ch=fgetc(p1))!=EOF) {
				if(ch<0||(ch>='0'&&ch<='9')||(ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
					printf("%c",ch);
			}
			printf("\n���������ʼ�˵���ѡ��:") ;
			scanf("%d",&b) ;
			if(b==1) input();
			if(b==2)  rfile ()  ;
			if(b==0)  exits() ;
		}
		if(e=='Y') {
			printf("�������ı���ѧ������");
			scanf("%d",&n);
			printf("�����뿼����Ŀ��");
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
			printf("\n��ѡ�����������Ĳ���\n") ;
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
				printf("����������Ҫ����������,��Y��N����\n");
				scanf(" %c",&a);
				if(a=='Y')  {
					next=1;
					printf("�����ѡ�����");
				} else next=0;
			}
		}
	}
	freememory(l) ;
	free(head);
	printf("       ��л����ʹ��");
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
			to=(ps->date.score[i][0]-48)*10+(ps->date.score[i][1]-48)+to;//��������˵��ܷ�
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
	for(i=0; i<n; i++) printf("��%d����%s �ܷ֣�%d\n",i+1,a[i].name,a[i].total);
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
			to=(ps->date.score[i][0]-48)*10+(ps->date.score[i][1]-48)+to;//��������˵��ܷ�
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
	for(i=0; i<n; i++) printf("��%d����%s �ܷ֣�%d\n",n--,a[i].name,a[i].total);
	return ;
}
void list (struct link*ps,int n,int m ) {
	int j;
	while(ps!=NULL) {
		printf("ѧ�ţ�%s ������ %s",ps->date.studentID,ps->date.name);
		printf("�ɼ���");
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
		printf("ѧ�ţ�%s ������ %s",p1[j]->date.studentID,p1[j]->date.name);
		printf("  �ɼ�:");
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
	printf("����������ѧ��\n") ;
	scanf("%s",a);
	while(ps!=NULL) {
		if(strcmp(ps->date.studentID,a)==0) {
			printf("ѧ�ţ�%s ������ %s",ps->date.studentID,ps->date.name);
			printf(" �ɼ���");
			for(j=0; j<m; j++)
				printf(" %s",ps->date.score[j]);
			printf("\n") ;
			flag=1;
		}
		ps=ps->next;
	}
	if(flag==0) printf("�Բ����������ѧ��δ���б����ҵ�") ;
	return ;
}
void searchname (struct link*ps,int n,int m) {
	int flag=0;
	int j;
	char a[11];
	printf("��������Ҫ��ѯ������\n") ;
	scanf("%s",a);
	while(ps!=NULL) {
		if(strcmp(ps->date.name,a)==0) {
			printf("ѧ�ţ�%s ������ %s",ps->date.studentID,ps->date.name);
			printf(" �ɼ���");
			for(j=0; j<m; j++)
				printf(" %s",ps->date.score[j]);
			printf("\n") ;
			flag=1;
		}
		ps=ps->next;
	}
	if(flag==0) printf("�Բ��������������δ���б����ҵ�") ;
	return ;
}
void statistic(struct link*ps,int n,int m) {
	struct link*p;
	p=ps;
	int flag=0;
	int i;
	int j;
	int a[5]= {0,0,0,0,0};
	printf("��������Ҫ�������Ŀ�Ŀ\n") ;
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
	printf("��������(90-100)��%d��\n",a[4]);
	while(ps!=NULL) {
		j=(ps->date.score[i-1][0]-48)*10+(ps->date.score[i-1][1]-48);
		if(j>=90&&j<=100)
			printf("%s  %s  %s\n",ps->date.studentID,ps->date.name,ps->date.score[i-1]);
		ps =ps->next ;
	}
	ps=p;
	printf("��������(80-89)��%d��\n",a[3]);
	while(ps!=NULL) {
		j=(ps->date.score[i-1][0]-48)*10+(ps->date.score[i-1][1]-48);
		if(j>=80&&j<90)
			printf("%s  %s  %s\n",ps->date.studentID,ps->date.name,ps->date.score[i-1]);
		ps =ps->next ;
	}
	ps=p;
	printf("�е�����(70-79)��%d��\n",a[2]);
	while(ps!=NULL) {
		j=(ps->date.score[i-1][0]-48)*10+(ps->date.score[i-1][1]-48);
		if(j>=70&&j<80)
			printf("%s  %s  %s\n",ps->date.studentID,ps->date.name,ps->date.score[i-1]);
		ps =ps->next ;
	}
	ps=p;
	printf("��������(60-69)��%d��\n",a[1]);
	while(ps!=NULL) {
		j=(ps->date.score[i-1][0]-48)*10+(ps->date.score[i-1][1]-48);
		if(j>=60&&j<70)
			printf("%s  %s  %s\n",ps->date.studentID,ps->date.name,ps->date.score[i-1]);
		ps =ps->next ;
	}
	ps=p;
	printf("����������(<60)��%d��\n",a[0]);
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
	printf("��������Ҫѡ��Ĳ���\n1.���һ��ѧ������Ϣ\n2.ɾ��һ��ѧ������Ϣ\n");
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
		printf("��������Ҫ�����ѧ����λ��");
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
		printf("������ѧ��");
		scanf("%s",p->date.studentID);
		printf("����������");
		scanf("%s",p->date.name);
		printf("��������Ƴɼ�");
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
		printf("������ѧ��");
		scanf("%s",p->date.studentID);
		printf("����������");
		scanf("%s",p->date.name);
		printf("��������Ƴɼ�");
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
		printf("������ѧ��");
		scanf("%s",p->date.studentID);
		printf("����������");
		scanf("%s",p->date.name);
		printf("��������Ƴɼ�");
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
	printf("������Ҫɾ����ѧ����Ϣ\n1.����    2.ѧ��\n");
	scanf(" %d",&a);
	if(a==1) {
		searchname(ps,n,m);
		char a[11];
		printf("\n��ȷ����Ҫɾ��������\n") ;
		scanf("%s",a);
		while(ps!=NULL) {
			if(strcmp(ps->date.name,a)==0) {
				printf("��ѧ����Ϣ�ѱ�ɾ��\n");
				ps->prev->next=ps->next;
				ps->next->prev=ps->prev;
				flag=1;
			}
			ps=ps->next;
		}
		if(flag==0) printf("�Բ��𣬸�ѧ����Ϣδ���ҵ�");
	}

	if(a==2) {
		char a[11];
		searchnumber(ps,n,m);
		printf("\n��ȷ����Ҫɾ����ѧ��\n") ;
		scanf("%s",a);
		while(ps!=NULL) {
			if(strcmp(ps->date.name,a)==0) {
				printf("��ѧ����Ϣ�ѱ�ɾ��\n");
				flag=1;
				ps->prev->next=ps->next;
				ps->next->prev=ps->prev;
			}
			ps=ps->next;
		}
		if(flag==0) printf("�Բ��𣬸�ѧ����Ϣδ���ҵ�");
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
