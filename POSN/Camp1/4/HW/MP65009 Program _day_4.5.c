#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	if (n >= 0) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i+1; j++) {
				printf("%c", 'A'+j);
			}
			printf("\n");
		}
	}
	else {
		printf("Invalid input");
	}
}
