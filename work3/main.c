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
	printf("Y:�l��\nN:�X�ͦ~���\n");
	scanf("%s",&data2);
	if(data2 == 'Y'){
		printf("�l��:%d\n",(data3+YY+MM+DD)%10);
	}
	else if(data2 == 'N'){
		printf("�X�ͦ~���:%d/%d/%d\n",YY,MM,DD);
	}
	else{
		printf("��J���~\n");
	}
	
	printf("�п�J�Ǹ�\n");
	scanf("%d",&data1);
	time_t time_data = time(0);
	strftime(time_out,sizeof(time_out),"%Y/%m/%d %X",localtime(&time_data));
	add1(data1);
	printf("�ʧO:�k\t");
	printf("�q�l�GB\n");
	printf("����ɶ�:");
	printf("%s\n",time_out);
	
	system("pause");
	return 0;
}

/*void add2(void){
	char data;
	printf("Y:�l��\nN:�X�ͦ~���\n");
	scanf("%s",&data);
	fflush(stdin);
	if(data == 'Y'){
		printf("�l��:%d\n",(data3+YY+MM+DD)%10);
	}
	else if(data == 'N'){
		printf("�X�ͦ~���:%d/%d/%d\n",YY,MM,DD);
	}
	else{
		
		add2();
	}
	
}*/

void add1(int data){
	printf("�m�W:�}�x�t");
	printf("\\�Ǹ�:%d\\\n",data);
	
	return;
}

