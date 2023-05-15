#include <stdio.h>

int main() {
	for (int i = 1; i <= 12; i++) {
		for (int j = 2; j <= 7; j++) {
			printf("%2dx%2d=%3d\t", j, i, j*i);
		}
		printf("\n");
	}
	printf("\n\n\n");
	for (int i = 1; i <= 12; i++) {
		for (int j = 8; j <= 13; j++) {
			printf("%2dx%2d=%3d\t", j, i, j*i);
		}
		printf("\n");
	}
}
