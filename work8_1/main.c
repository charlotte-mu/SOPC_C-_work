#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int data[5];
	int i,a,b,c;
	for(i=0;i<5;i++){
		data[i]=0;
	}
	while(1){
		system("cls");
		printf("�ثe�����U���[���p\n");
		printf("���[  ");
		for(i=1;i<=5;i++){
			printf("%4d",i);
		}
		printf("\n�H��  ");
		for(i=0;i<5;i++){
			printf("%4d",data[i]);
		}
		printf("\n���1:�W��  2:�U��  ");
		scanf("%d",&a);
		printf("��ܨ��[");
		scanf("%d",&b);
		printf("��J�H��");
		scanf("%d",&c);
		if(a==1){
			data[b-1] += c;
		}
		else if(a==2){
			data[b-1] -= c;
		}
		else{
			printf("���~");
			system("pause");
		}
	}
	return 0;
}
