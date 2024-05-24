#include <stdio.h>

int main() {
	char s[11], *sp;
	int i, vowels=0;
	scanf("%s", s);
	for (i = 0, sp = s; *sp != '\0'; i++, sp++) {
		if (*sp == 'a' || *sp == 'e' || *sp == 'i' || *sp == 'o' || *sp == 'u') vowels++;
	}
	printf("%d", vowels);
}
