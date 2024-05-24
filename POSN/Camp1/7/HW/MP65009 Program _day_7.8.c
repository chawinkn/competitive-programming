#include <stdio.h>

int main() {
	int i, j, *p1, *p2, temp, a[10] = {18, 20, 32, 2, 0, -5, 15, 102, 90, 1};
	for (i = 0, p1 = a; i < 9; i++, p1++) {
		for (j = i+1, p2 = a+i+1; j < 10; j++, p2++) {
			if (*p2 < *p1) {
				temp = *p2;
				*p2 = *p1;
				*p1 = temp;
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		printf("%d ", a[i]);
	}
}
