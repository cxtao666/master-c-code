#include <stdio.h> 
typedef struct clock
{
    int hour;

    int minute;

    int second;

} CLOCK;
CLOCK CalculateTime(CLOCK t1, CLOCK t2);
int main()
{  
	CLOCK a,b,d;
	printf("Input time one:(hour£¬minute):");
	scanf("%d,%d",&a.hour,&a.minute);
	printf( "Input time two: (hour£¬minute):");
	scanf("%d,%d",&b.hour,&b.minute); 
	printf("%dhour,%dminute\n",CalculateTime(a,b).hour,CalculateTime(a,b).minute);
    return 0;		
}
CLOCK CalculateTime(CLOCK t1, CLOCK t2)
{
  CLOCK c;
  	if((t1.hour*60+t1.minute)>=( t2.hour*60+t2.minute ))
	 {
	 c.hour=(t1.hour*60+t1.minute-t2.hour*60-t2.minute)/60 ;
	  c.minute=(t1.hour*60+t1.minute-t2.hour*60-t2.minute)%60;}
	 else {
	 c.hour=(t2.hour*60+t2.minute-t1.hour*60-t1.minute)/60 ;
	  c.minute=(t2.hour*60+t2.minute-t1.hour*60-t1.minute)%60;}
	return c;
}
