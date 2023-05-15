#include <stdio.h>

int main() {
	int a[10], t;
	for (int i = 0; i < 10; i++) {
		printf("Enter number %d : ", i+1);
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < 10; i++) {
		for (int j = i+1; j < 10; j++) {
			if (a[i] > a[j]) {
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
	printf("Ascending order : ");
	for (int i = 0; i < 10; i++) {
		printf("%d ", a[i]);
	}
}
