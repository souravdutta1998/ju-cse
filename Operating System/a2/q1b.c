#include<stdio.h>
#include<time.h>
#include<sys/time.h>

void delay(int second) {
	int totaldelay = CLOCKS_PER_SEC * second;
	clock_t curtime = clock();
	while(clock() < curtime + totaldelay)
	;
}
int main() {
	
	int i;
	for(i=1;i<=30;i++) {
		delay(1);
		printf("%2d second have elapsed.\n", i);
	}

	return 0;
}

