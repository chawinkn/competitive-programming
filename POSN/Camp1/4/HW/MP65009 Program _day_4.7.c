#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = n-i-1; j >= 1; j--) {
			printf(" ");
		}
		for (int j = i; j >= 1; j--) {
			printf("%d", j);
		}
		for (int j = 0; j <= i; j++) {
			printf("%d", j);
		}
		printf("\n");
	}
}
