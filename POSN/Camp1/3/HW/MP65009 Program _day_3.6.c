#include <stdio.h>

int main() {
	char c;
	printf("Enter character : ");
	scanf("%c", &c);
	printf("\n\n");
	if (c >= 'a' && c <= 'z') {
		c = 'A'+c-'a';
	}
	for (char i = c; i >= 'A'; i--) {
		printf("%c\n", i);
	}
}
