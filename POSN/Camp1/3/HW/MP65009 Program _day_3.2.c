#include <stdio.h>

int main() {
	int num, max, min;
	for (int i = 1; i <= 10; i++) {
		printf("Enter number %d : ", i);
		scanf("%d", &num);
		if (i == 1) {
			max = num;
			min = num;
		}
		if (num > max) {
			max = num;
		}
		if (num < min) {
			min = num;
		}
	}
	printf("Maximum = %d\n", max);
	printf("Minimum = %d", min);
}
