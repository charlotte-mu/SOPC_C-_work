#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void add1(void);

int main(int argc, char *argv[]) {
	
	char time_out[64];
	
	time_t time_data = time(0);
	strftime(time_out,sizeof(time_out),"%Y/%m/%d %X",localtime(&time_data));
	
	add1();
	printf("�ʧO:�k\t");
	printf("�q�l�GB\n");
	printf("����ɶ�:");
	printf("%s\n",time_out);
	//puts(time_out);
	
	system("pause");
	return 0;
}

void add1(void){
	printf("�m�W:�}�x�t");
	printf("\\�Ǹ�:106104201\\\n");
	
	return;
}
