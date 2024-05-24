#include <stdio.h>

int main() {
	int n, w;
	scanf("%d", &n);
	w = 2*n-1;
	for (int i = 1; i <= w; i++) {
		for (int j = 1; j <= w; j++) {
			if (i == j || j == w-i+1) {
				if (i <= w/2) {
					printf("%c", 'A'+n-i);
				}
				else {
					printf("%c", 'A'+i-n);
				}
			}
			else {
				 printf(" ");
			}
		}
		printf("\n");
	}
//	for (int i = 0; i < n-1; i++) {
//		for (int j = 0; j < i; j++) {
//			printf(" ");
//		}
//		for (int j = 0; j < 2*(n-i)-1; j++) {
//			if (j == 0 || j == 2*(n-i-1)) {
//				printf("%c", 'A'+n-i-1);
//			}
//			else {
//				printf(" ");
//			}
//		}
//		printf("\n");
//	}
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n-i-1; j++) {
//			printf(" ");
//		}
//		for (int j = 0; j < 2*i+1; j++) {
//			if (j == 0 || j == 2*i) {
//				printf("%c", 'A'+i);
//			}
//			else {
//				printf(" ");
//			}
//		}
//		printf("\n");
//	}
}
