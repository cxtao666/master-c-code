#include <stdio.h>
typedef struct winners

{
	char name[20];

	int finalScore;

	int classScore;

	char work;

	char west;

	int paper;

	int scholarship;
} WIN;
void Addup(WIN stu[], int n);
int FindMax(WIN student[], int n);

int main() {
	int n;
	printf("Input n:");
	scanf("%d",&n);
	WIN stu[n] ;
	Addup(stu, n);
	return 0;
}
void Addup(WIN stu[], int n) {
	int i,sum,j,sum1;
	for(i=0; i<n; i++) {
		sum=0;
		printf("Input name:");
		scanf("%s",stu[i].name);
		printf("Input final score:");
		scanf("%d",&stu[i].finalScore);
		printf("Input class score:");
		scanf("%d",&stu[i].classScore);
		printf("Class cadre or not?(Y/N):");
		scanf(" %c" ,&stu[i].work);
		printf("Students from the West or not?(Y/N):");
		scanf(" %c" ,&stu[i].west);
		printf("Input the number of published papers:");
		scanf("%d",&stu[i].paper);
		if(stu[i].classScore>80&&stu[i].work=='Y') sum=sum+850;
		if(stu[i].finalScore>85&&stu[i].west=='Y') sum=sum+1000;
		if(stu[i].finalScore>90) sum=sum+2000;
		if(stu[i].finalScore>85&&stu[i].classScore>80) sum=sum+4000;
		if(stu[i].finalScore>80&&stu[i].paper>=1) sum=sum+8000;
		printf( "name:%s,scholarship:%d\n",stu[i].name,sum);
		if(FindMax(stu,n)==sum) { j=i;sum1=sum; }
	} 
		if(FindMax(stu,n)==sum1) printf("%s get the highest scholarship %d\n",stu[j].name,sum1) ; 
		return ;
	}
int FindMax(WIN student[], int n) 
	{
		int i,sum,max=0;
		int a[n];
		for(i=0; i<n; i++) {
			int sum=0;
			if(student[i].classScore>80&&student[i].work=='Y') sum=sum+850;
			if(student[i].finalScore>85&&student[i].west=='Y') sum=sum+1000;
			if(student[i].finalScore>90) sum=sum+2000;
			if(student[i].finalScore>85&&student[i].classScore>80) sum=sum+4000;
			if(student[i].finalScore>80&&student[i].paper>=1) sum=sum+8000;
			a[i]=sum;
		}
		for(i=0; i<n; i++) {
			if(a[0]<=a[i])
				if(a[i]>max)
					max=a[i];
		}
		return max ;

	}

