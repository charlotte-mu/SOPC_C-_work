#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define size 50

void print(int );
void clear(void);
void random_number(int );
void print_test(int );
int from_to(int ,int ,int ,int ,int );
int data[size*2+1][size*2+1];

int main(int argc, char *argv[]) {
	int size_in;
	int x_from,y_from;
	int x_to,y_to;
	clear();
	do{
		printf("請輸入矩陣大小(Max=50):");
		scanf("%d",&size_in);
		if(size_in<=0 || size_in>50){
			printf("輸入矩陣大小erro\n");
		}
	}while(size_in<=0 || size_in>50);
	random_number(size_in);
	print(size_in);
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
	
	data[y_from*2+1][x_from*2+1]=2;
	if(from_to(x_from*2+1,y_from*2+1,size_in,x_to,y_to)==2){
		printf("00000000");
	}
	//print(size_in);
//	print_test(size_in);
	system("pause");
	return 0;
}

int from_to(int x,int y,int size_in,int x_to,int y_to){
	system("cls");
	print(size_in);
	//system("pause");
	if(x==x_to*2+1 && y==y_to*2+1){
		system("pause");
		return 1;
	}
	if(x>0){
		if(data[y][x+1]==0 && data[y][x+2] != 2){
			data[y][x+2] = 2;
			from_to(x+2,y,size_in,x_to,y_to);
			data[y][x+2] = 3;
		}
	}
	if(x<size_in*2+1){
		if(data[y][x-1]==0 && data[y][x-2] != 2){
			data[y][x-2] = 2;
			from_to(x-2,y,size_in,x_to,y_to);
			data[y][x-2] = 3;
		}
	}
	if(y>0){
		if(data[y+1][x]==0 && data[y+2][x] != 2){
			data[y+2][x] = 2;
			from_to(x,y+2,size_in,x_to,y_to);
			data[y+2][x] = 3;
		}
	}
	if(y<size_in*2+1){
		if(data[y-1][x]==0 && data[y-2][x] != 2){
			data[y-2][x] = 2;
			from_to(x,y-2,size_in,x_to,y_to);
			data[y-2][x] = 3;
		}
	}
	return 2;
}

void random_number(int size_in){
	srand(time(NULL));
	int x,y,ans;
	for(y=0;y<size_in*2+1;y++){
		for(x=size_in*2;x>=0;x--){
			if((x!=0 && y!=0) && (x!=size_in*2 && y!=size_in*2)){
				if((x%2==0 || y%2==0) && !(x%2==0 && y%2==0)){
					ans = rand()%4;
					if(ans == 0 || ans == 1|| ans == 2){
						data[y][x] = 0;
					}
				}
			}
		}
	}
}

/*void random_number(int size_in){
	srand(time(NULL));
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
*/ 
void print(int size_in){

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD saved_sttributes;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(hConsole, &csbiInfo);
	saved_sttributes = csbiInfo.wAttributes;
	
	int x,y;
	printf("y\\x");
	for(x=size_in-1;x>=0;x--){
		printf(" %2d ",x);
	}
	printf("\n");
	for(y=0;y<size_in*2+1;y++){
		for(x=size_in*2;x>=0;x--){
			if(data[y][x]==2){
				SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
				printf("@");
				SetConsoleTextAttribute(hConsole,saved_sttributes);
				//printf(" ");
			}
			else if(data[y][x]==1){
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
						printf("  ");
					}
				}
			}
			else if(data[y][x]==3){
				printf(" ");
			}
			else{
				printf("   ");
			}
		}
		printf("\n");
	}
}

void clear(void){
	int x,y;
	for(y=0;y<size*2+1;y++){
		for(x=size*2;x>=0;x--){
			if(y%2==1 && x%2==1){
				data[y][x] = 3;
			}
			else{
				data[y][x] = 1;
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
