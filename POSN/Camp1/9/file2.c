#include <stdio.h>

int main() {
	FILE *fp;
	int i, num;
	fp = fopen("E:\\a2.txt", "w");
	for (i = 0; i < 10; i++) {
		scanf("%d", &num);
		fprintf(fp, "%d ", num);
	}
	fclose(fp);
}
