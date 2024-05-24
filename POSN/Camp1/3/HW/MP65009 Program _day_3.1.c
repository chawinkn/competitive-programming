#include <stdio.h>

int main() {
	int num, sum=0;
	float mean;
	for (int i = 1; i <= 10; i++) {
		printf("Enter number %d : ", i);
		scanf("%d", &num);
		sum += num;
	}
	mean = sum/10;
	printf("Mean = %.2f", mean);
}
