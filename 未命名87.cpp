#include <stdio.h>
#include <string.h>
int main() {
	char p[7][10]= {"sunday","monday","tuesday","wednesday","thursday" ,"friday","saturday" } ;
	char a;
	char b;
	int i;
	int k=0;
	int j;
	int c=0;
	printf("please input the first letter of someday:\n");
	scanf(" %c",&a);
	for(i=0; i<7; i++) 
	{
		if(p[i][0]-32==a||p[i][0]==a) {
			k++;
			j=i;
		} 
	}
	 if(k==0) printf("data error");
	if(k==1)
		printf("%s",p[j]);
	if(k==2) {
		printf("please input second letter:\n");
		scanf(" %c",&b);
		for(i=0; i<7; i++)
			if(p[i][0]-32==a||p[i][0]==a) {
				if(p[i][1]-32==b||p[i][1]==b) {
					printf("%s",p[i]);c++;}
				}
				if(c==0) printf("data error"); 
			}
			return 0;
	}

