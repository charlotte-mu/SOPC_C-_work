#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define size 20

void print(int );
void clear(void);
void random_number(int );
void print_test(int );
int data[size*3][size*3];

int main(int argc, char *argv[]) {
	int size_in;
	clear();
	data[3][1]=2;
	printf("½Ð¿é¤J¯x°}¤j¤p:");
	scanf("%d",&size_in);
	random_number(size_in);
	print(size_in);
	print_test(size_in);
	system("pause");
	return 0;
}

void random_number(int size_in){
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

void print(int size_in){

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD saved_sttributes;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(hConsole, &csbiInfo);
	saved_sttributes = csbiInfo.wAttributes;
	
	int x,y;
	printf("\\  ");
	for(y=0;y<size_in;y++){
		printf("%2d ",y);
	}
	printf("\n");
	for(y=0;y<size_in*2+1;y++){
		for(x=0;x<size_in*2+1;x++){
			if(data[y][x]==2){
				SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
				printf("@");
				SetConsoleTextAttribute(hConsole,saved_sttributes);
			}
			else if(data[y][x]==1){
				if(y==0){
					if(x==0){
						printf("  ùÝ");
					}
					else if(x==size_in*2){
						printf("ùß");
					}
					else if(x%2==0){
						printf("ùÞ");
					}
					else if(x%2==1){
						printf("ùùùù");
					}
				}
				else if(y==size_in*2){
					if(x==0){
						printf("  ùã");
					}
					else if(x==size_in*2){
						printf("ùå");
					}
					else if(x%2==0){
						printf("ùä");
					}
					else if(x%2==1){
						printf("ùùùù");
					}
				}
				else if(y%2==0){
					if(x==0){
						printf("  ùà");
					}
					else if(x==size_in*2){
						printf("ùâ");
					}
					else if(x%2==0){
						printf("ùá");
					}
					else if(x%2==1){
						printf("ùùùù");
					}
				}
				else if(y%2==1){
					if(x==0){
						printf("%2d",y/2);
					} 
					if(x%2==0){
						printf("ùø ");
					}
					else{
						printf("  ");
					}
				}
			}
			else{
				printf("  ");
			}
		}
		printf("\n");
	}
}

void clear(void){
	int x,y;
	for(y=0;y<size*3;y++){
		for(x=0;x<size*3;x++){
			if(y%2==1 && x%2==1){
				data[y][x] = 2;
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
		for(x=0;x<size_in*2+1;x++){
			printf("%2d",data[y][x]);
		}
		printf("\n");
	}
}
