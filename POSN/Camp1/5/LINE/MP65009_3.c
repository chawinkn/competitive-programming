#include <stdio.h>

int main() {
	int n, c=0, b[32];
	printf("Enter decimal : ");
	scanf("%d", &n);
	if (n != 0) {
		while (n > 0) {
			b[c] = n%2;
			n /= 2;
			c++;
		}
		printf("Binary : ");
		for (int i = c-1; i >= 0; i--) {
			printf("%d", b[i]);
		}
	}
	else {
		printf("Binary : 0");
	}
}
