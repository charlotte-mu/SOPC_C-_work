#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void add1(int data);

int main(int argc, char *argv[]) {
	
	char time_out[64];
	int data1;
	
	printf("�п�J�Ǹ�\n");
	scanf("%d",&data1);
	
	time_t time_data = time(0);
	strftime(time_out,sizeof(time_out),"%Y/%m/%d %X",localtime(&time_data));
	
	add1(data1);
	printf("�ʧO:�k\t");
	printf("�q�l�GB\n");
	printf("����ɶ�:");
	printf("%s\n",time_out);
	//puts(time_out);
	
	system("pause");
	return 0;
}

void add1(int data){
	printf("�m�W:�}�x�t");
	printf("\\�Ǹ�:%d\\\n",data);
	
	return;
}
