#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	if (n != 0) {
		while (n > 0) {
			printf("%d", n%10);
			n /= 10;
			c = 1;
		}
	}
	else {
		printf("0");
	}
}
