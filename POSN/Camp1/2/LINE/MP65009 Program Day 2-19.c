#include <stdio.h>

int main() {
	int m, n, t[10]={1000, 500, 100, 50, 20, 10, 5, 2, 1};
	printf("Enter money for change : ");
	scanf("%d", &m);
	for (int i = 0; i < 9; i++) {
		if (m >= t[i]) {
			n = m/t[i];
			m -= n*t[i];
			printf("%4d Baht = %d\n", t[i], n);
		}
	}
}
