#include <stdio.h>
#include <string.h>

int main() {
	char s[101];
	int n, p = 1;
	printf("Enter string : ");
	gets(s);
	n = strlen(s);
	for (int i = 0; i < n; i++) {
		if (s[i] != s[n-i-1]) {
			p = 0;
			break;
		}
	}
	if (p) {
		printf("%s is a Palindrome", s);
	}
	else {
		printf("%s is not a Palindrome", s);
	}
}
