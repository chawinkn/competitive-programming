#include <stdio.h>

int main() {
	int score[10], pass=0, fail=0;
	for (int i = 0; i < 10; i++) {
		printf("Enter score %d : ", i+1);
		scanf("%d", &score[i]);
		if (score[i] >= 50) pass++;
		else fail++;
	}
	printf("Pass : %d\n", pass);
	printf("Fail : %d", fail);
}
