#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
typedef struct student
{
  long studentID;	
	char name[10] ;
	int score[6] ;
 } STUDENT;
void input(); //录入每个学生的学号.姓名和各科考试成绩
void course(STUDENT str[],int n,int m); //计算每门课程的总分和平均分
void stdudent(); //计算每个学生的总分和平均分
void descending();//按每个学生的总分由高到低排出名次表
void ascending();//按每个学生的总分由低到高排出名次表
void number() ;//按学号由小到大排出成绩表
void name();//按姓名的字典顺序排出成绩表
void searchnumber ();//按学号查询学生排名及其考试成绩
void searchname () ;//按姓名查询学生排名及其考试成绩
void statistic() ;//按照您的要求划分类别，并统计该类别内学生人数和所占百分比
void list ();//输出每个学生的信息
void wfile(STUDENT str[],int n,int m);// 将学生信息写入文件
void rfile (); //将信息从文件中读出
void exits();//退出
void help () ; //帮助 
int main()
{    int a,n=0;
   printf("       欢迎来到学生成绩管理系统！\n");
    printf("将为您提供以下服务\n");
        printf("1.录入学生信息\n");
        printf("2.从文件中读取学生信息\n");
        printf("3.查看功能\n");
        printf("0.退出\n");
  printf("请输入您的需求\n");
        scanf("%d",&a);
       while (a<0||a>3) {printf("您的输入有误，请重新选择。\n");scanf(" %d",&a);}
         while (a==3)
		 { help ();printf("请您继续录入信息");scanf("%d",&a); }   
        if(a==1) input();
      if(a==2) rfile () ;    
        if(a==0)  exits() ;
  return 0;

}
void help() 
{        printf("0.退出\n");
		printf("1.录入每个学生的学号.姓名和各科考试成绩\n");
	printf("2.计算每门课程的总分和平均分\n");
	printf("3.计算每个学生的总分和平均分\n") ;
	printf("4.按每个学生的总分由高到低排出名次表\n"); 
 	printf("5.按每个学生的总分由低到高排出名次表\n");
	printf("6.按学号由小到大排出成绩表\n");
	printf("7.按姓名的字典顺序排出成绩表\n");
	printf("8.按学号查询学生排名及其考试成绩\n");
	printf("9.按姓名查询学生排名及其考试成绩\n");
	printf("10.按照您的要求划分类别，并统计该类别内学生人数和所占百分比\n");
        printf("11.输出每个学生的信息\n");
        printf("12.从文件中读出每个学生的记录信息并显示\n");
        return ;
}
void input()
{ int i,j;
  int n;
  int m;
  int choice;
  char a;
  int next=1;
  printf("请输入人数");
  scanf("%d",&n);
  printf("请输入多少门成绩");	
  scanf("%d",&m) ;
  STUDENT str[n];
  for(i=0;i<n;i++)
  {
    printf("请输入学号");scanf("%ld",&str[i].studentID);
    printf("请输入姓名"); scanf("%s",str[i].name) ;
	printf("请输入各科成绩");
	for(j=0;j<m;j++)
	{ scanf("%d",&str[i].score[j]); } 
	}
	printf("想要将信息保存到文件中吗？请输入Y或N\n");
	scanf(" %c",&a);
	 if(a=='Y') wfile(str,n,m);
	 printf("请选择您接下来的操作\n") ;
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
	printf("请问您还需要其它操作吗,按Y或N继续\n");
	scanf(" %c",&a);
	 if(a=='Y')  {next=1;printf("请继续选择操作"); }
	 else next=0;
}  
     printf("       感谢您的使用"); 
	 return;
}
void wfile(STUDENT str[],int n,int m)
{  int i,j;
  FILE *p;
  char path[100];
 printf("请输入文件路径\n") ;
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
 printf("请输入文件路径\n") ;
  scanf("%s",path);
  p1=fopen(path,"r+");
  if(p1==NULL) 
  {printf("对不起该路径下不存在该文件，是否输入信息，按Y或N继续\n");
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
 











