/*signal2.c*/

#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void(*old_fun)(int);

void sigint_handler(int signo){

	printf("ctrl-c 키를 누르셨죠!!\n");
	prinitf("또 누르시면 종료됩니다.\n");
	signal(SIGINT,old_fun); //또는 signal(SIGINT, SIG_DFL);
}

int main(void){
	old_fun = signal(SIGINT, sigint_handler);

	while(1){
		printf("signal hander registered!\n");
		sleep(1);
	}
	return(0);
}
