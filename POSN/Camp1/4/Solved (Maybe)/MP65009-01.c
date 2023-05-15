#include <stdio.h>

int main() {
	int n, np;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		np = 0;
		for (int j = 2; j < i; j++) {
			if (i%j == 0) {
				np = 1;
				break;	
			}
		}
		if (np || i == 1) {
			printf("%d ", i);
		}
	}
}
