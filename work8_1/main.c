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
		printf("目前火車各車廂狀況\n");
		printf("車廂  ");
		for(i=1;i<=5;i++){
			printf("%4d",i);
		}
		printf("\n人數  ");
		for(i=0;i<5;i++){
			printf("%4d",data[i]);
		}
		printf("\n選擇1:上車  2:下車  ");
		scanf("%d",&a);
		printf("選擇車廂");
		scanf("%d",&b);
		printf("輸入人數");
		scanf("%d",&c);
		if(a==1){
			data[b-1] += c;
		}
		else if(a==2){
			data[b-1] -= c;
		}
		else{
			printf("錯誤");
			system("pause");
		}
	}
	return 0;
}
