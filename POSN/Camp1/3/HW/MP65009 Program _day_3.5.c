#include <stdio.h>

int main() {
	int a, b;
	printf("Enter number 1 : ");
	scanf("%d", &a);
	printf("Enter number 2 : ");
	scanf("%d", &b);
	printf("\n\nNumber that can divide by %d and %d\n", a, b);
	for (int i = 1; i <= 1000; i++) {
		if (i%a == 0 && i%b == 0) {
			printf("%d\n", i);
		}
	}
}
