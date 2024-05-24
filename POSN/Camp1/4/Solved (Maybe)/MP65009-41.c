#include <stdio.h>

int main() {
	int n, w;
	scanf("%d", &n);
	w = 2*n-1;
	// Top
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= w; j++) {
			if (j >= i && j <= w-i+1) {
				printf("%c ", 'A'+n-i);  
			}
			else if (j < i) {
				printf("%c ", 'A'+n-j);
			}
			else {
				printf("%c ", 'A'+j-n);
			}
		}
	printf("\n");  
	}
	// Bottom
	for (int i = n-1; i >= 1; i--) {
		for (int j = w; j >= 1; j--) {
			if (j >= i && j <= w-i+1) {
				printf("%c ", 'A'+n-i);  
			}
			else if (j < i) {
				printf("%c ", 'A'+n-j);
			}
			else {
				printf("%c ", 'A'+j-n);
			}
		}
		printf("\n");  
	}
}
