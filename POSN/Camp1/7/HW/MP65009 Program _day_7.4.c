#include <stdio.h>

int main() {
	int i;
	char s[11], *sp;
	scanf("%s", s);
	for (i = 0, sp = s; *sp != '\0'; i++, sp++) {
		if (*sp >= 'a' && *sp <= 'z') {
			*sp -= 32;
			printf("%c", *sp);
		}
		else {
			printf("%c", *sp);
		}
	}
}
