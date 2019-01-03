#include <stdio.h>
#include <stdlib.h>
#define size 20
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void print(int size_in);
void clear(void);
int data[size*3][size*3];

int main(int argc, char *argv[]) {
	int size_in;
	clear();
	data[1][1]=2;
	printf("½Ð¿é¤J¯x°}¤j¤p:");
	scanf("%d",&size_in);
	print(size_in);
	system("pause");
	return 0;
}

void print(int size_in){
	int i,j;
	printf("\\");
	for(i=0;i<size_in;i++){
		printf("%2d",i);
	}
	printf("\n");
	for(i=0;i<size_in*2;i++){
		for(j=0;j<size_in*2;j++){
			if(data[i][j]==2){
				printf(" @");
			}
			else if(data[i][j]==1){
				if(i==0){
					if(j==0){
						printf("  ùÝ");
					}
					else if(j==size_in*3-1){
						printf("ùß");
					}
					else if(j%2==0){
						printf("ùÞ");
					}
					else if(j%2==1){
						printf("ùùùù");
					}
				}
				else if(i==size_in*3-1){
					if(j==0){
						printf("  ùã");
					}
					else if(j==size_in*3-1){
						printf("ùå");
					}
					else if(j%2==0){
						printf("ùä");
					}
					else if(j%2==1){
						printf("ùùùù");
					}
				}
				else if(i%2==0){
					if(j==0){
						printf("  ùà");
					}
					else if(j==size_in*3-1){
						printf("ùâ");
					}
					else if(j%2==0){
						printf("ùá");
					}
					else if(j%2==1){
						printf("ùùùù");
					}
				}
				else if(i%2==1){
					if(j==0){
						printf("%2d",i/3);
					} 
					if(j%2==0){
						printf("ùø");
					}
					else{
						printf("¡@");
					}
				}
			}
			else{
				printf("¡@");
			}
		}
		printf("\n");
	}
}

void clear(void){
	int i,j;
	for(i=0;i<size*3;i++){
		for(j=0;j<size*3;j++){
			data[i][j] = 1;
		}
	}
}
