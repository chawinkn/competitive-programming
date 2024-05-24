#include<stdio.h>

int main() {
	FILE *fp;
	fp = fopen("E:\\002.txt", "r");
	char name[10];
	int age, i = 1;
	float weigth;
	while(!feof(fp)){
		fscanf(fp, "%s %d %f\n", name, &age, &weigth);
		printf("%d %s\t\t%d\t%.2f\n", i, name, age, weigth);
		i++;
	}
	fclose(fp);
}
