#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */



void clr(int *);
void add(int *,int *,int*,int *);
void print(int *,int *);

int main(int argc, char *argv[]) {
	int m,y,nxt,str;
	m = 0;
	y = 1500;
	nxt = 0;
	int endday[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	char mon[12][4] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
	int day1[42],day2[42];
	while(1){
		system("cls");
		clr(day1);
		clr(day2);
		add(&nxt,&endday[m],day1,&y);
		add(&nxt,&endday[m+1],day2,&y);
//		printf("\n --- Hello Calender %s --- \t --- Hello Calender %s --- \n",mon[m],mon[m+1]);
		printf(" ---    %4d / %s      --- \t ---    %4d / %s      --- \n",y,mon[m],(m+1 == 11)? y+1:y,mon[(m+1 == 11)? 0 : m+1]);
		m = m+2;
		if(m >11){
			m = 0;
			y++;
		}
		print(day1,day2);
/*		int i=0;
		for(i = 0;i<42;i++)
			printf("%2d %2d\n",day1[i],day2[i]);*/
		system("pause");
	}
	return 0;
}

void clr(int *day){
	int i,d;
	for(i=0;i<42;i++){
		*(day+i) = 0;
	}
}

void add(int *str ,int *end,int *day,int *y){
	int a,b;
	a = 1;
	b = *str;
	while(a <= *end){
		*(day + b++) = a++;
	}
	if(*end == 28){
		if(((*y%4 == 0) && (*y%100 != 0 )) || (*y%400 == 0 )){
			*(day + b++) = a++;
		}
	}
	*str = b%7;
	return;
}
void print(int *day1,int *day2){
	int a,b,c,d;
	a = 0;
	d = 0;
	printf(" Sun Mon Tur Wen Thu Fri Sat \t Sun Mon Tur Wen Thu Fri Sat\n");
	for(b = 0;b < 6;b++){
		for(c = 0;c < 7;c++){
			if(*(day1+a)==0){
				printf("    ");
			}
			else{
				printf("%4d",*(day1 + a));
			}
			a++;
		}
		printf("\t");
		for(c = 0;c < 7;c++){
			if(*(day2+d)==0){
				printf("    ");
			}
			else{
				printf("%4d",*(day2 + d));
			}
			d++;
		}
		printf("\n");
	}
	printf("\n");
}
