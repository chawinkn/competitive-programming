#include <stdio.h>

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 7-i; j >= 0; j--) {
			printf(" ");
		}
		for (int j = 0; j < 2*i+1; j++) {
			if (j == 0 || j == 2*i) {
				printf("%d", i+1);
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
}
