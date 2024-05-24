#include <stdio.h>

int main() {
	int n, m, c=0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			printf(" ");
		}
		for (int j = 0; j < m; j++) {
			printf("%c", 'A'+c%26);
			c++;
		}
		printf("\n");
	}
}
