#include <stdio.h>

int main() {
	int age;
	printf("Enter Number : ");
	scanf("%d", &age);
	if (age < 20) {
		printf("young");
	}
	else if (age <= 50) {
		printf("smart");
	}
	else if (age > 50) {
		printf("old");
	}
}
