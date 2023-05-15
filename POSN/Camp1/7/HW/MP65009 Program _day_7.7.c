#include <stdio.h>

int main() {
	int a[10], b[10], *p1, *p2, i, d, num, sum=0;
	for (i = 0, p1 = a; i < 10; i++, p1++) {
		scanf("%d", &num);
		*p1 = num;
	}
	for (i = 0, p2 = b; i < 10; i++, p2++) {
		scanf("%d", &num);
		*p2 = num;
	}
	for (i = 9, d = 1, p1 = a+9, p2 = b+9; i > -1; i--, d*=10, p1--, p2--) {
		sum += (*p1+*p2)*d;
	}
	printf("%d", sum);
}
