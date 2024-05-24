#include <stdio.h>
#include <string.h>

int main() {
	char name[101], sur[101], gen[7], res[301];
	printf("Enter name : ");
	scanf("%s", name);
	printf("Enter surname : ");
	scanf("%s", sur);
	printf("Enter gender : ");
	scanf("%s", gen);
	if (strcmp(gen, "Male") == 0) {
		strcat(res, "Mr. ");
	}
	else if (strcmp(gen, "Female") == 0) {
		strcat(res, "Mrs. ");
	}
	strcat(res, name);
	strcat(res, " ");
	strcat(res, sur);
	printf("%s", res);
}
