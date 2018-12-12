#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define data3 1
#define YY 87
#define MM 10
#define DD 29

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void add1(int data);
void add2(void);

int main(int argc, char *argv[]) {
	
	char time_out[64],data2;
	int data1;
	
	
	//add2();
	printf("Y:餘數\nN:出生年月日\n");
	scanf("%s",&data2);
	if(data2 == 'Y'){
		printf("餘數:%d\n",(data3+YY+MM+DD)%10);
	}
	else if(data2 == 'N'){
		printf("出生年月日:%d/%d/%d\n",YY,MM,DD);
	}
	else{
		printf("輸入錯誤\n");
	}
	
	printf("請輸入學號\n");
	scanf("%d",&data1);
	time_t time_data = time(0);
	strftime(time_out,sizeof(time_out),"%Y/%m/%d %X",localtime(&time_data));
	add1(data1);
	printf("性別:男\t");
	printf("電子二B\n");
	printf("日期時間:");
	printf("%s\n",time_out);
	
	system("pause");
	return 0;
}

/*void add2(void){
	char data;
	printf("Y:餘數\nN:出生年月日\n");
	scanf("%s",&data);
	fflush(stdin);
	if(data == 'Y'){
		printf("餘數:%d\n",(data3+YY+MM+DD)%10);
	}
	else if(data == 'N'){
		printf("出生年月日:%d/%d/%d\n",YY,MM,DD);
	}
	else{
		
		add2();
	}
	
}*/

void add1(int data){
	printf("姓名:慕庭宇");
	printf("\\學號:%d\\\n",data);
	
	return;
}

