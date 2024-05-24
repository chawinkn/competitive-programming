#include <stdio.h>

int main() {
	int a[5] = {-1,6,9,2,-9}, b[5];
	for (int i = 0; i < 5; i++) {
		if (a[i] >= 0) b[i] = a[i];
		else b[i] = -a[i];
	}
	printf("Absolute : ");
	for (int i = 0; i < 5; i++) {
		printf("%d ", b[i]);
	}
	return 0;
}
