#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define size 20
#define time_reg 300

void gotoxy(int xpos, int ypos);
void print(int);
void clear(int );
void random_number(void);
void print_test(void);
void from_to(int ,int ,int ,int ,int ,int ,int* ,int*,int ,int,int ,int ,int);
void d_bug(int* ,int*);
void delay(void);

int data[size*2+1][size*2+1],data_reg[size*2+1][size*2+1];
int size_in;

int main(int argc, char *argv[]) {
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD saved_sttributes;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(hConsole, &csbiInfo);
	saved_sttributes = csbiInfo.wAttributes;
	
	clock_t start, end;
	double cpu_time_used;
	
	srand(time(NULL));
	int x_from,y_from;
	int x_to,y_to;
	int x_buffer,y_buffer;
	int cmd;
	int ans,ans_reg;
	clear(1);
	do{
		printf("請輸入矩陣大小(Max=%d):",size);
		scanf("%d",&size_in);
		if(size_in<=0 || size_in>size){
			printf("輸入矩陣大小erro\n");
		}
	}while(size_in<=0 || size_in>size);
	random_number();
	start = clock();
	d_bug(&ans,&ans_reg);
	end = clock();
	print(0);
	//print_test(size_in);
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("計算時間=%f\n", cpu_time_used);
	do{
		printf("請輸入起點(x,y):");
		scanf("%d %d",&x_from,&y_from);
		if(x_from<0 || x_from>=size_in || y_from<0 || y_from>=size_in){
			printf("輸入座標erro\n");
		}
	}while(x_from<0 || x_from>=size_in || y_from<0 || y_from>=size_in);
	do{
		printf("請輸入中繼點(x,y):");
		scanf("%d %d",&x_buffer,&y_buffer);
		if(x_buffer<0 || x_buffer>=size_in || y_buffer<0 || y_buffer>=size_in){
			printf("輸入座標erro\n");
		}
	}while(x_buffer<0 || x_buffer>=size_in || y_buffer<0 || y_buffer>=size_in);
	do{
		printf("請輸入終點(x,y):");
		scanf("%d %d",&x_to,&y_to);
		if(x_to<0 || x_to>=size_in || y_to<0 || y_to>=size_in){
			printf("輸入座標erro\n");
		}
	}while(x_to<0 || x_to>=size_in || y_to<0 || y_to>=size_in);
	
	ans_reg = size_in*size_in;
	ans = 0;
	printf("系統忙錄中，請稍後...\n");
	start = clock();
	from_to(x_from*2+1,y_from*2+1,x_to,y_to,2,0,&ans,&ans_reg,x_from,y_from, x_buffer, y_buffer,0);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("計算時間=%f\n", cpu_time_used);
	system("pause");
	
	while(1){
		do{
			system("cls");
			print(0);
			printf("1:顯示全部路徑  2:顯示最佳路徑  3:結束\n");
			scanf("%d",&cmd);
			if(cmd<1 || cmd>3){
				printf("輸入錯誤\n");
			}
		}while(cmd<1 || cmd>3);
		if(cmd==3){
			break;
		}
		else if(cmd==1){
			ans = 0;
			gotoxy((size_in-x_from)*4+1,y_from*2+1+1);
			SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN);
			printf("@");
			SetConsoleTextAttribute(hConsole,saved_sttributes);
			from_to(x_from*2+1,y_from*2+1,x_to,y_to,3,0,&ans,&ans_reg,x_from,y_from, x_buffer, y_buffer,0);
		}
		else if(cmd==2){
			print(1);
			printf("最佳路徑步數%d\n",ans_reg);
			system("pause");
		}
		if(ans==0){
			gotoxy(0,size_in*2+4);
			printf("erro-沒有路徑\n");
			system("pause");
		}
	}
	//print_test(size_in);
	//system("pause");
	return 0;
}

void from_to(int x,int y,int x_to,int y_to,int cmd,int step,int *ans,int *ans_reg,int x_from,int y_from,int x_buffer,int y_buffer,int key){
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD saved_sttributes;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(hConsole, &csbiInfo);
	saved_sttributes = csbiInfo.wAttributes;
	int i,j;
	
	if(cmd==0 && *ans!=0){
		return;
	}
	else if(cmd == 1){
		system("cls");
		print(0);
	}
	else if(cmd==3){
		delay();
		gotoxy((size_in-(x_from))*4+1,y_from*2+1+1);
		if(x==x_to*2+1 && y==y_to*2+1){
			SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
		}
		else{
			if(key==0){
				SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN);
			}
			else{
				SetConsoleTextAttribute(hConsole,FOREGROUND_BLUE);
			}
			
		}
		printf("@");
		SetConsoleTextAttribute(hConsole,saved_sttributes);
	}
	if((key==1)? (x==x_to*2+1 && y==y_to*2+1) : (x==x_buffer*2+1 && y==y_buffer*2+1)){
		if(key==0){
			data[y][x] = 2;
			key = 1;
		}
		else{
			data[y][x] = 4;
			if(cmd==1 || cmd==3){
				if(cmd==3){
					gotoxy(0,size_in*2+4);
					printf("                                   \n");
					printf("                                   \n");
					gotoxy(0,size_in*2+4);
				}
				printf("此路徑步數%d，最佳路徑步數%d\n",step,*ans_reg);
				system("pause");
			}
			else if(cmd==2){
				if(step<*ans_reg){
					*ans_reg = step;
					//memcpy(data_reg, data, sizeof(data_reg));
					for(i=0;i<size_in*2+1;i++){
						for(j=0;j<size_in*2+1;j++){
							if(data_reg[i][j]!=2){
								data_reg[i][j] = data[i][j];
							}
						}
					}
				}
			}
			*ans = *ans + 1;
			if(cmd==3){
				gotoxy((size_in-(x_from))*4+1,y_from*2+1+1);
				printf(" ");
			}
			data[y][x] = 3;
			return;
		}
	}
	else{
		if(key==0){
			data[y][x] = 2;
		}
		else{
			data[y][x] = 5;
		}
	}
	if(x>0){
		if(data[y][x+1]==0 && data[y][x+2] != 2 && data[y][x+2] != 5){
			from_to(x+2,y,x_to,y_to,cmd,step+1,ans,ans_reg,x_from+1,y_from,x_buffer,y_buffer,key);
		}
	}
	if(x<size_in*2+1){
		if(data[y][x-1]==0 && data[y][x-2] != 2 && data[y][x-2] != 5){
			from_to(x-2,y,x_to,y_to,cmd,step+1,ans,ans_reg,x_from-1,y_from,x_buffer,y_buffer,key);
		}
	}
	if(y>0){
		if(data[y+1][x]==0 && data[y+2][x] != 2 && data[y+2][x] != 5){
			from_to(x,y+2,x_to,y_to,cmd,step+1,ans,ans_reg,x_from,y_from+1,x_buffer,y_buffer,key);
		}
	}
	if(y<size_in*2+1){
		if(data[y-1][x]==0 && data[y-2][x] != 2 && data[y-2][x] != 5){
			from_to(x,y-2,x_to,y_to,cmd,step+1,ans,ans_reg,x_from,y_from-1,x_buffer,y_buffer,key);
		}
	}
	if(cmd==3){
		gotoxy((size_in-(x_from))*4+1,y_from*2+1+1);
		printf(" ");
	}
	data[y][x] = 3;
	return;
}

void random_number(void){
	//srand(time(NULL));
	clear(0);
	int x,y;
	int reg;
	for(y=0;y<size_in*2+1;y++){
		for(x=0;x<size_in*2+1;x++){
			if((x!=0 && y!=0) && (x!=size_in*2 && y!=size_in*2)){
				if((x%2==0 || y%2==0) && !(x%2==0 && y%2==0)){
					reg = rand()%2;
					if(reg >= 0 && reg <= 0){
						data[y][x] = 0;
					}
				}
			}
		}
	}
}
void d_bug(int *ans,int *ans_reg){
	printf("系統忙錄中，請稍後...");
	do{
		//srand(time(NULL));
		do{
			*ans = 0;
			from_to(1,1,size_in-1,size_in-1,0,0,ans,ans_reg,0,0,0,0,1);
			if(*ans==0){
				random_number();
			}
		}while(*ans==0);
		*ans = 0;
		from_to(1,size_in*2-1,size_in-1,1,0,0,ans,ans_reg,0,0,0,0,1);
		if(*ans==0){
			random_number();
		}
	}while(*ans==0);
	system("cls");
}

void print(int cmd){

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD saved_sttributes;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(hConsole, &csbiInfo);
	saved_sttributes = csbiInfo.wAttributes;
	
	system("cls");
	int x,y;
	printf("y\\x");
	for(x=size_in-1;x>=0;x--){
		printf(" %2d ",x);
	}
	printf("\n");
	for(y=0;y<size_in*2+1;y++){
		for(x=size_in*2;x>=0;x--){
			if((cmd==0)?data[y][x]==5 : data_reg[y][x]==5){
				SetConsoleTextAttribute(hConsole,FOREGROUND_BLUE);
				printf("@");
				SetConsoleTextAttribute(hConsole,saved_sttributes);
			}
			else if((cmd==0)?data[y][x]==2 : data_reg[y][x]==2){
				SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN);
				printf("@");
				SetConsoleTextAttribute(hConsole,saved_sttributes);
			}
			else if((cmd==0)?data[y][x]==4 : data_reg[y][x]==4){
				SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
				printf("@");
				SetConsoleTextAttribute(hConsole,saved_sttributes);
			}
			else if((cmd==0)?data[y][x]==1 : data_reg[y][x]==1){
				if(y==0){
					if(x==0){
						printf("╗ ");
					}
					else if(x==size_in*2){
						printf("  ╔");
					}
					else if(x%2==0){
						printf("╦");
					}
					else if(x%2==1){
						printf(" ══");
					}
				}
				else if(y==size_in*2){
					if(x==0){
						printf("╝ ");
					}
					else if(x==size_in*2){
						printf("  ╚");
					}
					else if(x%2==0){
						printf("╩");
					}
					else if(x%2==1){
						printf(" ══");
					}
				}
				else if(y%2==0){
					if(x==0){
						printf("╣ ");
					}
					else if(x==size_in*2){
						printf("  ╠");
					}
					else if(x%2==0){
						printf("╬");
					}
					else if(x%2==1){
						printf(" ══");
					}
				}
				else if(y%2==1){
					if(x==size_in*2){
						printf("%2d",y/2);
					} 
					if(x%2==0){
						printf("║  ");
					}
					else{
						printf("　");
					}
				}
			}
			else if((cmd==0)?data[y][x]==3 : data_reg[y][x]==3){
				printf(" ");
			}
			else{
				printf("   ");
			}
		}
		printf("\n");
	}
}

void clear(int cmd){
	int x,y;
	for(y=0;y<size*2+1;y++){
		for(x=size*2;x>=0;x--){
			if(y%2==1 && x%2==1){
				if(cmd==0){
					data[y][x] = 3;
				}
				else{
					data_reg[y][x] = 3;
				}
			}
			else{
				if(cmd==0){
					data[y][x] = 1;
				}
				else{
					data_reg[y][x] = 1;
				}
			}
		}
	}
}
void print_test(void){
	int x,y;
	printf("\n");
	for(y=0;y<size_in*2+1;y++){
		for(x=size_in*2;x>=0;x--){
			printf("%2d",data[y][x]);
		}
		printf("\n");
	}
}

void gotoxy(int xpos, int ypos){
  COORD scrn;
  HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
  scrn.X = xpos; scrn.Y = ypos;
  SetConsoleCursorPosition(hOuput,scrn);
}

void delay(void){
	int a,b,c;
	for(a=0;a<time_reg;a++){
		for(b=0;b<time_reg;b++){
			for(c=0;c<time_reg;c++){
				
			}
		}
	}
}

/*void d_bug(int x,int y,int size_in){
	srand(time(NULL));
	int reg;
	if(data[y][x+1]==1 && data[y][x-1]==1 && data[y+1][x]==1 && data[y-1][x]==1){
		if(x==1 && y==1){
			reg = rand()%2;
			if(reg==0){
				data[y][x+1] = 0;
			}
			else if(reg==1){
				data[y+1][x] = 0;
			}
		}
		else if(x==1 && y==size_in*2){
			reg = rand()%2;
			if(reg==0){
				data[y][x+1] = 0;
			}
			else if(reg==1){
				data[y-1][x] = 0;
			}
		}
		else if(x==size_in*2 && y==1){
			reg = rand()%2;
			if(reg==0){
				data[y][x-1] = 0;
			}
			else if(reg==1){
				data[y+1][x] = 0;
			}
		}
		else if(x==size_in*2 && y==size_in*2){
			reg = rand()%2;
			if(reg==0){
				data[y][x-1] = 0;
			}
			else if(reg==1){
				data[y-1][x] = 0;
			}
		}
		else if(x==1){
			reg = rand()%3;
			if(reg==0){
				data[y][x+1] = 0;
			}
			else if(reg==1){
				data[y-1][x] = 0;
			}
			else if(reg==2){
				data[y+1][x] = 0;
			}
		}
		else if(x==size_in*2){
			reg = rand()%3;
			if(reg==0){
				data[y][x-1] = 0;
			}
			else if(reg==1){
				data[y-1][x] = 0;
			}
			else if(reg==2){
				data[y+1][x] = 0;
			}
		}
		else if(y==size_in*2){
			reg = rand()%3;
			if(reg==0){
				data[y][x+1] = 0;
			}
			else if(reg==1){
				data[y][x-1] = 0;
			}
			else if(reg==2){
				data[y-1][x] = 0;
			}
		}
		else if(y==1){
			reg = rand()%3;
			if(reg==0){
				data[y][x+1] = 0;
			}
			else if(reg==1){
				data[y][x-1] = 0;
			}
			else if(reg==2){
				data[y+1][x] = 0;
			}
		}
		else{
			reg = rand()%4;
			if(reg==0){
				data[y][x+1] = 0;
			}
			else if(reg==1){
				data[y][x-1] = 0;
			}
			else if(reg==2){
				data[y+1][x] = 0;
			}
			else if(reg==3){
				data[y-1][x] = 0;
			}
		}
	}
	
}
*/

/*void random_number(int size_in){
	srand(time(NULL));
	int x,y,ans;
	for(y=0;y<size_in*2+1;y++){
		for(x=size_in*2;x>=0;x--){
			if((x!=0 && y!=0) && (x!=size_in*2 && y!=size_in*2)){
				if((x%2==0 && y%2==1)){
					if(rand()%2 == 0){
						data[y][x] = 0;
						data[y+1][x-1] = 1;
					}
					else{
						data[y][x] = 1;
						data[y+1][x-1] = 0;
					}
				}
			}
		}
	}
}*/

