#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void in(int);
void add(int *,int);

int main(int argc, char *argv[]) {
	int data;
	while(1){
		system("cls");
		printf("請問要輸入幾個數? ");
		scanf("%d",&data);
		in(data);
	}
	return 0;
}
void in(int f){
	int data[f];
	int i;
 	for(i=0;i<f;i++){
 		scanf("%d",&data[i]);	
	}
	add(&data,f);
	for(i=0;i<f;i++){
 		printf("%4d",data[i]);	
	}
	printf("\n");	
	system("pause");
}
void add(int *data,int a){
	int i,j,b,reg;
	printf("1:小到大 2:大到小");
	scanf("%d",&b);
	if(b==1){
		for(j=0;j<a;j++){
			for(i=0;i<a-1;i++){
				if(*(data+i)>*(data+i+1)){
					reg = *(data+i);
					*(data+i) = *(data+i+1);
					*(data+i+1) = reg;
				}
			}
		}
	}
	else if(b==2){
		for(j=0;j<a;j++){
			for(i=0;i<a-1;i++){
				if(*(data+i)<*(data+i+1)){
					reg = *(data+i);
					*(data+i) = *(data+i+1);
					*(data+i+1) = reg;
				}
			}
		}
	}
	else{
		printf("錯誤");
		system("pause");
	}
}

