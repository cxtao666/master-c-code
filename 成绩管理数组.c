#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
typedef struct student
{
  long studentID;	
	char name[10] ;
	int score[6] ;
 } STUDENT;
void input(); //¼��ÿ��ѧ����ѧ��.�����͸��ƿ��Գɼ�
void course(STUDENT str[],int n,int m); //����ÿ�ſγ̵��ֺܷ�ƽ����
void stdudent(); //����ÿ��ѧ�����ֺܷ�ƽ����
void descending();//��ÿ��ѧ�����ܷ��ɸߵ����ų����α�
void ascending();//��ÿ��ѧ�����ܷ��ɵ͵����ų����α�
void number() ;//��ѧ����С�����ų��ɼ���
void name();//���������ֵ�˳���ų��ɼ���
void searchnumber ();//��ѧ�Ų�ѯѧ���������俼�Գɼ�
void searchname () ;//��������ѯѧ���������俼�Գɼ�
void statistic() ;//��������Ҫ�󻮷���𣬲�ͳ�Ƹ������ѧ����������ռ�ٷֱ�
void list ();//���ÿ��ѧ������Ϣ
void wfile(STUDENT str[],int n,int m);// ��ѧ����Ϣд���ļ�
void rfile (); //����Ϣ���ļ��ж���
void exits();//�˳�
void help () ; //���� 
int main()
{    int a,n=0;
   printf("       ��ӭ����ѧ���ɼ�����ϵͳ��\n");
    printf("��Ϊ���ṩ���·���\n");
        printf("1.¼��ѧ����Ϣ\n");
        printf("2.���ļ��ж�ȡѧ����Ϣ\n");
        printf("3.�鿴����\n");
        printf("0.�˳�\n");
  printf("��������������\n");
        scanf("%d",&a);
       while (a<0||a>3) {printf("������������������ѡ��\n");scanf(" %d",&a);}
         while (a==3)
		 { help ();printf("��������¼����Ϣ");scanf("%d",&a); }   
        if(a==1) input();
      if(a==2) rfile () ;    
        if(a==0)  exits() ;
  return 0;

}
void help() 
{        printf("0.�˳�\n");
		printf("1.¼��ÿ��ѧ����ѧ��.�����͸��ƿ��Գɼ�\n");
	printf("2.����ÿ�ſγ̵��ֺܷ�ƽ����\n");
	printf("3.����ÿ��ѧ�����ֺܷ�ƽ����\n") ;
	printf("4.��ÿ��ѧ�����ܷ��ɸߵ����ų����α�\n"); 
 	printf("5.��ÿ��ѧ�����ܷ��ɵ͵����ų����α�\n");
	printf("6.��ѧ����С�����ų��ɼ���\n");
	printf("7.���������ֵ�˳���ų��ɼ���\n");
	printf("8.��ѧ�Ų�ѯѧ���������俼�Գɼ�\n");
	printf("9.��������ѯѧ���������俼�Գɼ�\n");
	printf("10.��������Ҫ�󻮷���𣬲�ͳ�Ƹ������ѧ����������ռ�ٷֱ�\n");
        printf("11.���ÿ��ѧ������Ϣ\n");
        printf("12.���ļ��ж���ÿ��ѧ���ļ�¼��Ϣ����ʾ\n");
        return ;
}
void input()
{ int i,j;
  int n;
  int m;
  int choice;
  char a;
  int next=1;
  printf("����������");
  scanf("%d",&n);
  printf("����������ųɼ�");	
  scanf("%d",&m) ;
  STUDENT str[n];
  for(i=0;i<n;i++)
  {
    printf("������ѧ��");scanf("%ld",&str[i].studentID);
    printf("����������"); scanf("%s",str[i].name) ;
	printf("��������Ƴɼ�");
	for(j=0;j<m;j++)
	{ scanf("%d",&str[i].score[j]); } 
	}
	printf("��Ҫ����Ϣ���浽�ļ�����������Y��N\n");
	scanf(" %c",&a);
	 if(a=='Y') wfile(str,n,m);
	 printf("��ѡ�����������Ĳ���\n") ;
	help();
		while(next==1)
  {	scanf ("%d",&choice );
    if(choice==2) course( str, n, m) ;
	else if(choice==3)  ;
	else if(choice==4)   ; 
	else if(choice==5)   ;
	else if(choice==6)   ;
	else if(choice==7)    ;
	else if(choice==8)   ;
	else if(choice==9)    ;
	else if(choice==10)    ;
	else if(choice==11)    ;
	else if(choice==12)    ;
	else if(choice==13)    ;
	else if(choice==1)  input()  ;
	else exits();
	printf("����������Ҫ����������,��Y��N����\n");
	scanf(" %c",&a);
	 if(a=='Y')  {next=1;printf("�����ѡ�����"); }
	 else next=0;
}  
     printf("       ��л����ʹ��"); 
	 return;
}
void wfile(STUDENT str[],int n,int m)
{  int i,j;
  FILE *p;
  char path[100];
 printf("�������ļ�·��\n") ;
  scanf("%s",path);
  p=fopen(path,"a+");	
	if(p==NULL)  p=fopen("D:\\information.txt","w");
	if(p==NULL)  p=fopen("D:\\information.txt","a+");
	for(i=0;i<n;i++)
	 {
	 	fprintf(p,"%10ld%8s",str[i].studentID,str[i].name);
	 	for(j=0;j<m;j++)
	 	fprintf(p,"%4d",str[i].score[j]);
	 	fprintf(p,"\n");
	 }
	 fclose(p);
}
void course(STUDENT str[],int n,int m)
{  int i; int j;int a[m];float b[m];
   float aver=0; int and=0;
   float c=m;
   for(j=0;j<m;j++)
     for(i=0;i<n;i++)
    {
    and=str[i].score[j]+and;
	a[j]=and;	
}
   for(j=0;j<m;j++)
   { printf("%d  ",a[j]);
    aver=a[j]/c;
    b[j]=aver;
   }
   printf("\n");
for(j=0;j<m;j++) printf("%0.2f ",b[j]);
 printf("\n");
  return ;
}
void exits()
{
  exit(0);
}
void rfile () 
{   char a;int i;
    int j;int k;
  char path[100];
  FILE *p1;
 printf("�������ļ�·��\n") ;
  scanf("%s",path);
  p1=fopen(path,"r+");
  if(p1==NULL) 
  {printf("�Բ����·���²����ڸ��ļ����Ƿ�������Ϣ����Y��N����\n");
   	scanf(" %c",&a);
   	 if(a=='Y')  input();} 
     else {
     STUDENT str[1000];
	 	 	for(i=0;!feof(p1);i++)
	 	 	{ fread(&str[i],sizeof(STUDENT),1,p1);}
	 	 	j=i;
     	for(i=0;i<j;i++)
     	 {   printf("%10ld%8s",str[i].studentID,str[i].name);
     	 for(k=0;str[i].score[k]>0;k++) printf("%d",str[i].score[k]);
     }
        fclose(p1);
     	return ;
     	
	 }





} 
 











