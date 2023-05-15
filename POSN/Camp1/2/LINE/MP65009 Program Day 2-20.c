#include <stdio.h>

int main() {
	int p, m, n, c, t[10]={1000, 500, 100, 50, 20, 10, 5, 2, 1};
	printf("Enter money for product : ");
	scanf("%d", &p);
	printf("Enter amount of paid : ");
	scanf("%d", &m);
	c = m-p;
	printf("Change money total : %d Baht\n", c);
	for (int i = 0; i < 9; i++) {
		if (c >= t[i]) {
			n = c/t[i];
			c -= n*t[i];
			printf("%4d Baht = %d\n", t[i], n);
		}
	}
}
