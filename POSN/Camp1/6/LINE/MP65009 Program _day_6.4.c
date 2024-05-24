#include <stdio.h>

int main() {
	char s[21];
	printf("Enter string : ");
	gets(s);
	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] >= 'a' && s[i] <= 'z') s[i] -= 'a'-'A';
		else if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 'a'-'A';
	}
	printf("Result = %s", s);
}
