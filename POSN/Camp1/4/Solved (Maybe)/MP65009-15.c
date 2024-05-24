#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-i-1; j++) printf(" ");
		for (int j = 0; j < 2*i+1; j++) {
			if (j == 0 || j == 2*i) printf("%c", 'A'+i);
			else printf(" ");
		}
		printf("\n");
	}
	for (int i = n-2; i > -1; i--) {
		for (int j = 0; j < n-i-1; j++) printf(" ");
		for (int j = 0; j < 2*i+1; j++) {
			if (j == 0 || j == 2*i) printf("%c", 'A'+i);
			else printf(" ");
		}
		printf("\n");
	}
}
