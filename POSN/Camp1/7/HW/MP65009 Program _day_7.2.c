#include <stdio.h>

int main() {
	char s1[11], s2[11], *sp1, *sp2;
	printf("Enter string 1 : ");
	scanf("%s", s1);
	sp1 = s1;
	sp2 = s2;
	for (int i = 0; *sp1 != '\0'; i++, sp1++, sp2++) {
		*sp2 = *sp1;
	}
	*sp2 = '\0';
	printf("String 1 = %s\n", s1);
	printf("String 2 = %s", s2);
}
