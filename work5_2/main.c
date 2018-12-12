#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a ,b;
	for(a = 1;a < 10;a++){
		b = 5;
		do{
			printf("%d*%d= %2d   ",a ,b ,a*b);
			if(b++ == 10) b = 1;
		}while(b != 5);
		printf("\n");
	}
	system("pause");
	return 0;
}
