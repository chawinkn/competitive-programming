#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1, x = 2; i <= n; i++, x*=2) {
		printf("%d\t%d\n", i, x);
	}
}
