#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void print(int*,int);
void ai(int *,int ,int ,int ,int ,int ,int *);
void bug(int *,int );

int main(int argc, char *argv[]) {
	int data_i,data_from,data_to,data_ctrl,data_reg;
	int i,j;
	int reg;
	reg = 0;
	printf("請輸入河內塔層數: ");
	scanf("%d",&data_i);
	int data[data_i][3];
	do{
		printf("請輸入河內塔初始位置:\n1: A\n2: B\n3: C \n");
		scanf("%d",&data_from);
		if(data_from < 1 || data_from > 3){
			printf("輸入超出範圍，請重新輸入\n");
		}
	}while(data_from < 1 || data_from > 3);
	for(i=0;i<data_i;i++){
		data[i][0] = 0;
		data[i][1] = 0;
		data[i][2] = 0;
		if(data_from == 1){
			data[i][0] = i;
		}
		else if(data_from == 2){
			data[i][1] = i;
		}
		else if(data_from == 3){
			data[i][2] = i;
		}
	}
	system("cls");
	print(&data[0][0],data_i);
	
	do{
		printf("\n請輸入操作方式:\n1: 自動\n2: 手動\n");
		scanf("%d",&data_ctrl);
		if(data_ctrl < 1 || data_ctrl > 2){
			printf("輸入超出範圍，請重新輸入\n");
		}
	}while(data_ctrl < 1 || data_ctrl > 2);
	
	if(data_ctrl == 1){
		do{
			printf("\n請輸入河內塔目標置:\n1: A\n2: B\n3: C \n");
			scanf("%d",&data_to);
			if(data_to < 1 || data_to > 3){
				printf("輸入超出範圍，請重新輸入\n");
			}
			else if(data_to == data_from){
				printf("起始與目標位置重複，請重新輸入\n");
			}
		}while(data_to < 1 || data_to > 3 || data_to == data_from);
		for(i=1;i<4;i++){
			if(i != data_from && i != data_to){
				data_reg = i;
			}
		}
		ai(&data[0][0],data_i,data_i,data_from-1,data_to-1,data_reg-1,&reg);
	}
	else if(data_ctrl == 2){
		while(1){
			bug(&data[0][0],data_i);
		}
	}
	/*system("cls");
	print(&data[0][0],data_i);
	*/ 
	system("pause");
	return 0;
}

void print(int *data,int data_i){
	int i,j,k;
	char data_reg[3]={'A','B','C'};
	printf("  \\");
	for(i=0;i<3;i++){
		for(j=0;j<data_i+2;j++){
			printf(" ");
		}
		printf("%c",data_reg[i]);
		for(j=0;j<data_i+2;j++){
			printf(" ");
		}
	}
	printf("\n");
	for(i=0;i<data_i;i++){
		printf("%2d ",i);
		for(k=0;k<3;k++){
			for(j=0;j< data_i - *(data+3*i+k)+2;j++){
				printf(" ");
			}
			for(j=0;j<*(data+3*i+k);j++){
				printf("M");
			}
			printf("|");
			for(j=0;j<*(data+3*i+k);j++){
				printf("M");
			}
			for(j=0;j<data_i-*(data+3*i+k)+2;j++){
				printf(" ");
			}
		}
		printf("\n");
	}
	printf("===");
	for(i=0;i<(data_i+2)*6;i++){
		printf("=");
	}
	printf("===");
}


void ai(int *data,int data_i,int data_i_reg,int data_from,int data_to,int data_reg,int *reg){
	int i,from,to;
	if(data_i_reg == 0){
		return;
	}
	ai(data,data_i,data_i_reg-1,data_from,data_reg,data_to,reg);
	from = 0;
	to = 0;
	for(i=0;i<data_i;i++){
		if(*(data+i*3+data_from) != 0){
			from = i;
			break;
		}
	}
	for(i=data_i-1;i>=0;i--){
		if(*(data+i*3+data_to) == 0){
			to = i;
			break;
		}
	}
	*(reg) += 1;
	*(data+to*3+data_to) = *(data+from*3+data_from);
	*(data+from*3+data_from) = 0;
	
	system("cls");
	print(data,data_i);
	printf("\n第%d步  D%d  %c => %c \n",*(reg),data_i_reg,(data_from==0)?'A':(data_from==1)?'B':'C',(data_to==0)?'A':(data_to==1)?'B':'C');
//	system("pause");
	ai(data,data_i,data_i_reg-1,data_reg,data_to,data_from,reg);
	
}

void bug(int *data,int data_i){
	int data_from,data_to;
	int from,to;
	int i;
	do{
		printf("\n請輸入搬移目標與目的地(From,To):\n1: A\n2: B\n3: C \n");
		scanf("%d %d",&data_from,&data_to);
		if(data_from < 1 || data_from > 3 || data_to < 1 || data_to > 3){
			printf("輸入超出範圍，請重新輸入\n");
		}
	}while(data_from < 1 || data_from > 3 || data_to < 1 || data_to > 3);
	data_to -= 1;
	data_from -= 1;
	for(i=0;i<data_i;i++){
		if(*(data+i*3+data_from) != 0){
			from = i;
			break;
		}
	}
	for(i=data_i-1;i>=0;i--){
		if(*(data+i*3+data_to) == 0){
			to = i;
			break;
		}
	}
	*(data+to*3+data_to) = *(data+from*3+data_from);
	*(data+from*3+data_from) = 0;
	system("cls");
	print(data,data_i);
}

