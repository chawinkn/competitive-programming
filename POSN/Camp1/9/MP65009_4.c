#include<stdio.h>
int main() {
	FILE *fp = fopen("E:\\004.txt", "a");
	char name[20];
	int age;
	float weight;
	printf("Insert new name: ");
	scanf("%s", name);
	printf("Insert new age: ");
	scanf("%d", &age);
	printf("Insert new weight: ");
	scanf("%f", &weight);
	fprintf(fp, "\n%s %d %.0f", name, age, weight);
	printf("Added to file");
}
