#include <stdio.h>

int main() {
	int sum = 0;
	char num[101];
	printf("Enter number (100 MAX) : ");
	scanf("%s", &num);
	for (int i = 0; num[i] != '\0'; i++) {
		sum += num[i]-'0';		
	}
	printf("Sum total is %d", sum);
}
