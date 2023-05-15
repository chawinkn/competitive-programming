#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	for (int i = n-1; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			if (i+j==n-1) printf("\\");
			else printf(" ");
		}
		for (int j = n-1; j >= 0; j--) {
			if (i+j==n-1) printf("/");
			else printf(" ");
		}
		printf("\n");
	}
}
