#include <stdio.h>

int main() {
	int n, c=-1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		c += i+1;
		for (int j = 0, k = c; j < i+1; j++, k--) {
			printf("%c", 'A'+k%26);
		}
		printf("\n");
	}
	//	char arr[n][n];
	//	for (int i = 0; i < n; i++) {
	//		for (int j = i; j >= 0; j--) {
	//			arr[i][j] = 'A'+c%26;
	//			c++;
	//		}
	//	}
	//	for (int i = 0; i < n; i++) {
	//		for (int j = 0; j <= i; j++) {
	//			printf("%c", arr[i][j]);
	//		}
	//		printf("\n");
	//	}
}
