#include <stdio.h>

int main() {
	int n, c=0;
	scanf("%d", &n);
	if (n >= 0) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i+1; j++) {
				printf("%c", 'A'+c%26);
				c++;
			}
			printf("\n");
		}
	}
	else {
		printf("Invalid input");
	}
}
