#include <stdio.h>

int main() {
	int num, p=1;
	printf("Enter number : ");
	scanf("%d", &num);
	for (int i = 2; i < num; i++) {
		if (num%i == 0) p = 0;
	}
	if (p && num >= 2) {
		printf("%d is a prime number", num);
	}
	else {
		printf("%d is not a prime number", num);
	}
}
