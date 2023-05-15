#include <stdio.h>

int main() {
	char s[21], c;
	printf("Enter string : ");
	gets(s);
	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			s[i] -= 'a' - 'A';	
		}
	}
	printf("Toupper = %s", s);
}
