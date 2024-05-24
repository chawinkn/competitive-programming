#include <stdio.h>

int main() {
	int s, n, i;
	scanf("%d", &s);
	scanf("%d", &n);
	for (i = 1; i < s; i++) {
		printf("  \t");
	}
	for (i = 1; i <= n; i++) {
		if (s%7 == 0) {
			printf("%2d\n", i);
		}
		else {
			printf("%2d\t", i);
		}
		s++;
	}
}
