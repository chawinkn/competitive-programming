#include <stdio.h>

int main() {
	char c;
	printf("Enter character : ");
	scanf("%c", &c);
	if (c >= 'A' && c <= 'Z') {
		printf("%c", c-'A'+'a');
	}
	else if (c >= 'a' && c <= 'z') {
		printf("%c", c-'a'+'A');
	}
	else {
		printf("Error");
	}
}
