#include <stdio.h>

int main() {
	FILE *fp;
	fp = fopen("E:\\a4.txt", "a");
	char s1[101], s2[101];
	int a;
	float h;
	printf("Enter first name : ");
	scanf("%s", s1);
	printf("Enter surname : ");
	scanf("%s", s2);
	printf("Enter age : ");
	scanf("%d", &a);
	printf("Enter height : ");
	scanf("%f", &h);
	fprintf(fp, "%s %s %d %.2f", s1, s2, a, h);
	fclose(fp);
}
