#include <stdio.h>

int main() {
	int score[3][3], pow[3][3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("Enter score %d %d : ", i, j);
			scanf("%d", &score[i][j]);
			pow[i][j] = score[i][j]*score[i][j];
		}
	}
	printf("\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d\t", pow[i][j]);
		}
		printf("\n");
	}
}
