#include <stdio.h>

int main() {
	int a[4], b[4], cnt=0;
	printf("Set A\n");
	for (int i = 0; i < 4; i++) {
		printf("Enter number %d : ", i+1);
		scanf("%d", &a[i]);
	}
	printf("Set B\n");
	for (int i = 0; i < 4; i++) {
		printf("Enter number %d : ", i+1);
		scanf("%d", &b[i]);
		if (a[i] == b[i]) cnt++;
	}
	printf("Same element count = %d", cnt);
}
