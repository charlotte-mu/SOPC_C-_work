#include <stdio.h>
#include <stdlib.h>
#define size 3
#define O "O"
#define X "X"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void print(int *);
int input(int *,int *);
int add_1(int *,int ,int ,int *,int *,int *);
int add_2(int *,int ,int ,int *,int *,int *);
int add_3(int *,int ,int ,int *,int *,int *);
int add_4(int *,int ,int ,int *,int *,int *);


int main(int argc, char *argv[]) {
	int data[size][size];
	int i,j;
	int data_run,ans;
	int O_ans,X_ans;
	int data_reg,data_OX;
	int add1,add2,add3,add4,ans_reg;
	data_run = 1;
	O_ans = 0;
	X_ans = 0;
	while(1){
		for(i=0;i<size;i++){
			for(j=0;j<size;j++){
				data[i][j] = 0;
			}
		}
		system("cls");
		print(&data[0][0]);
		while(1){
			printf("請輸入誰先手 1: %s(O) 先手 2: %s(X) 先手 :",O,X);
			scanf("%d",&data_OX);
			if(data_OX==1 || data_OX==2){
				break;
			}
			else{
				printf("輸入錯誤\n");
			}
		}
		for(i=0;i<size*size;i++){
			system("cls");
			print(&data[0][0]);
			printf("第%d回合\n",data_run);
			printf(" %s(O) 分數:%d   %s(X) 分數:%d\n\n",O,O_ans,X,X_ans);
			do{
				data_reg = input(&data[0][0],&data_OX);
			}while(data_reg == 0);
			if(data_reg==2){
				ans_reg = 3;
				break;
			}
			ans_reg = 0;
			add1 = add_1(&data[0][0],0,0,&O_ans,&X_ans,&data_run);
			add2 = add_2(&data[0][0],0,size-1,&O_ans,&X_ans,&data_run);
			add3 = add_3(&data[0][0],0,0,&O_ans,&X_ans,&data_run);
			add4 = add_4(&data[0][0],0,0,&O_ans,&X_ans,&data_run);
			ans_reg = add1 + add2 + add3 + add4;
			
			if(ans_reg != 0){
				break;
			}
		}
		system("cls");
		if(ans_reg == 1){
			printf("遊戲結束 本回合由 %s(O) 獲勝\n",O);
		}
		else if(ans_reg == 2){
			printf("遊戲結束 本回合由 %s(X) 獲勝\n",X);
		}
		else{
			printf("遊戲結束 本回合平手\n");
		}
		printf("比數為 %s(O):%d %s(X):%d\n",O,O_ans,X,X_ans);
		printf("是否繼續遊戲? 1:是 2:否");
		scanf("%d",&ans);
		if(ans==2){
			break;
		}
	}
	system("pause");
	return 0;
}


void print(int *data){
	int i,j,a;
	printf(" X  ");
	for(i=0;i<size;i++){
		printf("%x   ",i);
	}
	printf("\n");
	printf("Y -");
	for(i=0;i<size;i++){
		printf("----");
	}
	printf("\n");
	for(i=0;i<size;i++){
		printf("%x |",i);
		for(j=0;j<size;j++){
			switch(*(data + i*size + j)){
				case 0:{
					printf("   |");
					break;
				}
				case 1:{
					printf(" O |");
					break;
				}
				case 2:{
					printf(" X |");
					break;
				}
			}
		}
		printf("\n  -");
 		 for(a=0;a<size;a++){
			printf("----");
		}
		printf("\n");
	}
	printf("\n");
	
}


int input(int *data,int *data_OX){
	int x,y;
	if(*data_OX==1){
		printf(" %s(O) 下棋 請輸入座標X,Y: ",O);
	}
	else if(*data_OX==2){
		printf(" %s(X) 下棋 請輸入座標X,Y: ",X);
	}
	scanf("%d%d",&y,&x);
	if(x == 99 && y == 99){
		return 2;
	}
	else if(x >= size || y >= size){
		printf("座標輸入過大 請重新輸入\n");
		return 0;
	}
	else if(*(data + x*size +y) != 0){
		printf("此座標已有棋子 請重新輸入\n");
		return 0;
	}
	else{
		if(*data_OX==1){
			*(data + x*size +y) = 1;
			*data_OX = 2;
		}
		else if(*data_OX==2){
			*(data + x*size +y) = 2;
			*data_OX = 1;
		}
		return 1;
	}
}

int add_1(int *data,int x,int y,int *O_ans,int *X_ans,int *data_run){
	if(x==size-1&&y==size-1){
		*data_run+= 1  ;
		if(*(data + x*size +y)==1){
			*O_ans+= 1 ;
			return 1;
		}
		else if(*(data + x*size +y)==2){
			*X_ans+= 1 ;
			return 2;
		}
	}
	else if( *(data + x*size +y) == *(data + (x+1)*size + y + 1) && *(data + x*size +y) != 0){
		add_1(data,x+1,y+1,O_ans,X_ans,data_run);
	}
	else{
		return 0;
	}
}

int add_2(int *data,int x,int y,int *O_ans,int *X_ans,int *data_run){
	if(x==size-1&&y==0){
		*data_run+= 1  ;
		if(*(data + x*size +y)==1){
			*O_ans+= 1  ;
			return 1;
		}
		else if(*(data + x*size +y)==2){
			*X_ans+= 1  ;
			return 2;
		}
	}
	else if(*(data + x*size +y) == *(data + (x+1)*size + y - 1) && *(data + x*size +y) != 0){
		add_2(data,x+1,y-1,O_ans,X_ans,data_run);
	}
	else{
		return 0;
	}
}
int add_3(int *data,int x,int y,int *O_ans,int *X_ans,int *data_run){
	if(x==size-1){
		*data_run+= 1  ;
		if(*(data + x*size +y)==1){
			*O_ans += 1 ;
			return 1;
		}
		else if(*(data + x*size +y)==2){
			*X_ans+= 1  ;
			return 2;
		}
	}
	else if(*(data + x*size +y)==*(data + (x+1)*size + y) && *(data + x*size +y) != 0){
		add_3(data,x+1,y,O_ans,X_ans,data_run);
	}
	else if(y<size){
		add_3(data,0,y+1,O_ans,X_ans,data_run);
	}
	else{
		return 0;
	}
}
int add_4(int *data,int x,int y,int *O_ans,int *X_ans,int *data_run){
	if(y==size-1){
		*data_run+= 1  ;
		if(*(data + x*size +y)==1){
			*O_ans+= 1  ;
			return 1;
		}
		else if(*(data + x*size +y)==2){
			*X_ans+= 1  ;
			return 2;
		}
	}
	else if(*(data + x*size +y)==*(data + x*size + y + 1) && *(data + x*size +y) != 0){
		add_4(data,x,y+1,O_ans,X_ans,data_run);
	}
	else if(x<size){
		add_4(data,x+1,0,O_ans,X_ans,data_run);
	}
	else{
		return 0;
	}
}
