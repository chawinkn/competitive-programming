#include <stdio.h>

int main() {
	int n, d, *p, odd=0;
	scanf("%d", &n);
	p = &n;
	while (*p > 0) {
		d = *p%10;
		if (d%2 == 1) odd++;
		*p /= 10;
	}
	printf("%d", odd);
}
