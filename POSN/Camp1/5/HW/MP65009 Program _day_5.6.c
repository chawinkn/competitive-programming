#include <stdio.h>

int main() {
	int a[5] = {-1,6,9,2,-9}, m;
	m = a[0];
	for (int i = 0; i < 5; i++) {
		if (a[i] < m) m = a[i];
	}
	printf("Minimum : %d", m);
	return 0;
}
