#include <stdio.h>

int sum(int *p, int n) {
	int s = 0;
	for (int i = 0; i < n; i++, p++) {
		s += *p;
	}
	return s;
}

int main() {
	int arr[10];
	for (int i = 0; i < 10; i++) {
		scanf("%d", &arr[i]);
	}
	printf("%d", sum(arr, 10));
}
