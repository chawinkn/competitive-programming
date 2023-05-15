#include <stdio.h>

int main() {
	char s[101];
	int i, d=0, c=0, v=0;
	printf("Enter string : ");
	gets(s);
	for (i = 0; s[i] != '\0'; i++) {
		char n = s[i];
		if (n >= '0' && n <= '9') {
			d++;
			c++;
		}
		if (n >= 'A' && n <= 'Z') {
			n += 'a' - 'A';	
		}
		if (n >= 'a' && n <= 'z') {
			c++;
			if (n == 'a' || n == 'e' || n == 'i' || n == 'o' || n == 'u') {
				v++;
			}
		}
	}
	printf("Length = %d\n", i);
	printf("Number of character = %d\n", c);
	printf("Number of vowel = %d", v);
}
