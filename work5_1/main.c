#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char data;
	while(1){
		do{
			printf("�п�Ja~Z:");
			scanf("%s",&data);
		}while(!((data >= 0x41 && data <= 0x5a)||(data >= 0x61 && data <= 0x7a)));
		if(data >= 0x41 && data <= 0x5a) printf("�j�g%c\n",data);
		else if(data >= 0x61 && data <= 0x7a) printf("�p�g%c\n",data);
	}
	return 0;
}
