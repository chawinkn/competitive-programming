#include <stdio.h>

int main() {
	int score[10];
	for (int i = 0; i < 10; i++) {
		printf("Enter score %d : ", i+1);
		scanf("%d", &score[i]);
	}
}
