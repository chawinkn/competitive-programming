#include <stdio.h>

int main() {
	FILE *fp1, *fp2, *fp3;
	int i, a1, a2;
	fp1 = fopen("E:\\a1.txt", "r");
	fp2 = fopen("E:\\a2.txt", "r");
	fp3 = fopen("E:\\a3.txt", "a");
	for (i = 0; i < 10; i++) {
		fscanf(fp1, "%d\n", &a1);
		fscanf(fp2, "%d ", &a2);
		fprintf(fp3, "%d ", a1*a2);
	}
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
}
