#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define size 20

void print(int ,int);
void clear(int );
void random_number(int );
void print_test(int );
void from_to(int ,int ,int ,int ,int ,int ,int );
void d_bug(int );

int data[size*2+1][size*2+1],data_reg[size*2+1][size*2+1];
int ans,ans_reg;

int main(int argc, char *argv[]) {
	srand(time(NULL));
	int size_in;
	int x_from,y_from;
	int x_to,y_to;
	int cmd;
	clear(1);
	do{
		printf("請輸入矩陣大小(Max=%d):",size);
		scanf("%d",&size_in);
		if(size_in<=0 || size_in>50){
			printf("輸入矩陣大小erro\n");
		}
	}while(size_in<=0 || size_in>50);
	random_number(size_in);
	d_bug(size_in);
	print(size_in,0);
	//print_test(size_in);
	do{
		printf("請輸入起點(x,y):");
		scanf("%d %d",&x_from,&y_from);
		if(x_from<0 || x_from>=size_in || y_from<0 || y_from>=size_in){
			printf("輸入座標erro\n");
		}
	}while(x_from<0 || x_from>=size_in || y_from<0 || y_from>=size_in);
	do{
		printf("請輸入終點(x,y):");
		scanf("%d %d",&x_to,&y_to);
		if(x_to<0 || x_to>=size_in || y_to<0 || y_to>=size_in){
			printf("輸入座標erro\n");
		}
	}while(x_to<0 || x_to>=size_in || y_to<0 || y_to>=size_in);
	
	ans_reg = size_in*size_in;
	data[y_from*2+1][x_from*2+1]=2;
	ans = 0;
	from_to(x_from*2+1,y_from*2+1,size_in,x_to,y_to,2,0);
	
	while(1){
		do{
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
			data[y_from*2+1][x_from*2+1]=2;
			ans = 0;
			from_to(x_from*2+1,y_from*2+1,size_in,x_to,y_to,1,0);
		}
		else if(cmd==2){
			print(size_in,1);
			printf("最佳路徑步數%d\n",ans_reg);
		}
	}
	if(ans==0){
		printf("00000000");
	}
	//print_test(size_in);
	//system("pause");
	return 0;
}

void from_to(int x,int y,int size_in,int x_to,int y_to,int cmd,int step){
	if(cmd==0 && ans!=0){
		return;
	}
	if(cmd == 1){
		system("cls");
		print(size_in,0);
	}
	if(x==x_to*2+1 && y==y_to*2+1){
		if(cmd == 1){
			printf("此路徑步數%d，最佳路徑步數%d\n",step,ans_reg);
			system("pause");
		}
		else if(cmd==2){
			if(step<ans_reg){
				ans_reg = step;
				memcpy(data_reg, data, sizeof(data_reg));
			}
		}
		ans++;
		return;
	}
	if(x>0){
		if(data[y][x+1]==0 && data[y][x+2] != 2){
			if(x+2==x_to*2+1 && y==y_to*2+1){
				data[y][x+2] = 4;
			}
			else{
				data[y][x+2] = 2;
			} 
			from_to(x+2,y,size_in,x_to,y_to,cmd,step+1);
			data[y][x+2] = 3;
		}
	}
	if(x<size_in*2+1){
		if(data[y][x-1]==0 && data[y][x-2] != 2){
			if(x-2==x_to*2+1 && y==y_to*2+1){
				data[y][x-2] = 4;
			}
			else{
				data[y][x-2] = 2;
			}
			from_to(x-2,y,size_in,x_to,y_to,cmd,step+1);
			data[y][x-2] = 3;
		}
	}
	if(y>0){
		if(data[y+1][x]==0 && data[y+2][x] != 2){
			if(x==x_to*2+1 && y+2==y_to*2+1){
				data[y+2][x] = 4;
			}
			else{
				data[y+2][x] = 2;
			}
			from_to(x,y+2,size_in,x_to,y_to,cmd,step+1);
			data[y+2][x] = 3;
		}
	}
	if(y<size_in*2+1){
		if(data[y-1][x]==0 && data[y-2][x] != 2){
			if(x==x_to*2+1 && y-2==y_to*2+1){
				data[y-2][x] = 4;
			}
			else{
				data[y-2][x] = 2;
			}
			from_to(x,y-2,size_in,x_to,y_to,cmd,step+1);
			data[y-2][x] = 3;
		}
	}
	return;
}

void random_number(int size_in){
	//srand(time(NULL));
	clear(0);
	int x,y,ans;
	for(y=0;y<size_in*2+1;y++){
		for(x=0;x<size_in*2+1;x++){
			if((x!=0 && y!=0) && (x!=size_in*2 && y!=size_in*2)){
				if((x%2==0 || y%2==0) && !(x%2==0 && y%2==0)){
					ans = rand()%2;
					if(ans == 0){
						data[y][x] = 0;
					}
				}
			}
		}
	}
}
void d_bug(int size_in){
	printf("系統忙線中，請稍後...");
	do{
		srand(time(NULL));
		do{
			ans = 0;
			from_to(1,1,size_in,size_in-1,size_in-1,0,0);
			if(ans==0){
				random_number(size_in);
			}
		}while(ans==0);
		ans = 0;
		from_to(1,size_in*2-1,size_in,size_in-1,1,0,0);
		if(ans==0){
			random_number(size_in);
		}
	}while(ans==0);
	system("cls");
}

void print(int size_in,int cmd){

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
			if((cmd==0)?data[y][x]==2 : data_reg[y][x]==2){
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
void print_test(int size_in){
	int x,y;
	printf("\n");
	for(y=0;y<size_in*2+1;y++){
		for(x=size_in*2;x>=0;x--){
			printf("%2d",data[y][x]);
		}
		printf("\n");
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

