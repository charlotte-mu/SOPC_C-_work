#include <stdio.h>
#include <stdlib.h>
#define NAME "Willian"
#define SEX "Male"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void select(int *,int *);

int main(int argc, char *argv[]) {
	int data1,data2,data3;
	
	do{
		if(SEX == "Male"){
			printf("Hello,Mr.%s\n",NAME);
		}
		else if(SEX == "Female"){
			printf("Hello,Ms.%s\n",NAME);
		}
		else{
			printf("erro:�ʧO���~\n");
		}
		printf("�п�J�Ǹ�\n");
		scanf("%d",&data1);
		
		select(&data1,&data2);
		
		if(data2 == 0){
			printf("�Ǹ�������\n");
		}
		else{
			printf("�Ǹ����_��\n");
		}
		printf("�п�J �~��:Y ����:N\n");
		scanf("%s",&data3);
		
	}while(data3 == 'Y');
	system("pause");
	return 0;
}

void select(int *reg1,int *reg2){
	*reg2 = (*reg1%2);
}
