#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void add1(int data);

int main(int argc, char *argv[]) {
	
	char time_out[64];
	int data1;
	
	printf("請輸入學號\n");
	scanf("%d",&data1);
	
	time_t time_data = time(0);
	strftime(time_out,sizeof(time_out),"%Y/%m/%d %X",localtime(&time_data));
	
	add1(data1);
	printf("性別:男\t");
	printf("電子二B\n");
	printf("日期時間:");
	printf("%s\n",time_out);
	//puts(time_out);
	
	system("pause");
	return 0;
}

void add1(int data){
	printf("姓名:慕庭宇");
	printf("\\學號:%d\\\n",data);
	
	return;
}
