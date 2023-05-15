#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	if (n > 1 &&  n <= 10000) {
		for (int i = 2; i <= n; i++) {
			if (i%3==0 && i>=6) {
				printf("%d ", i);
			}
		}
	}
	else {
		printf("no");
	}
}
