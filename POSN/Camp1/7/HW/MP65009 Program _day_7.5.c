#include <stdio.h>

int main() {
	int i, palindrome=1, n=0;
	char s[11], *sp1, *sp2;
	scanf("%s", s);
	for (i = 0, sp1 = s, sp2 = s; *sp1 != '\0'; i++, sp1++, sp2++) {
		n++;
	}
	sp2 -= 1;
	for (i = 0, sp1 = s; i < n/2; i++, sp1++, sp2--) {
		if (*sp1 != *sp2) {
			palindrome = 0;
			break;
		}
	}
	if (palindrome) {
		printf("yes");
	}
	else {
		printf("no");
	}
}
