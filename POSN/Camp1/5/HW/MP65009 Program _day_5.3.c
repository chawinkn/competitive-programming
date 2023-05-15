#include <stdio.h>

int main() {
	int score[10], sum=0;
	float mean;
	for (int i = 0; i < 10; i++) {
		printf("Enter score %d : ", i+1);
		scanf("%d", &score[i]);
		sum += score[i];
	}
	mean = sum/10;
	printf("Sum : %d\n", sum);
	printf("Mean : %.2f", mean);
}
