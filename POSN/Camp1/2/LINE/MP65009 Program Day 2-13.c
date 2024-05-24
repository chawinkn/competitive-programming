#include <stdio.h>

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < i; j++) {
			printf(" ");
		}
		for (int j = 1; j <= 9-i; j++) {
			printf("%d", j);
		}
		printf("\n");
	}
}
