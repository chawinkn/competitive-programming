#include <stdio.h>

int main() {
	int n, num, max=0, min=100;
	printf("Enter n : ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		printf("Enter number %d : ", i+1);
		scanf("%d", &num);
		if (num > 0 && num < 100) {
			if (num > max) max = num;
			if (num < min) min = num;
		}
		else {
			printf("Invalid input");
			return 0;
		}
	}
	printf("Max = %d\nMin = %d", max, min);
}
