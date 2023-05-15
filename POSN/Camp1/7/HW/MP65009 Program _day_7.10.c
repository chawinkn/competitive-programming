#include <stdio.h>
#include <string.h>

int main() {
	int i, j, c, n, len=0;
	char s1[11], s2[11], *p1, *p2;
	scanf("%s", s1);
	scanf("%s", s2);
	for (i = 0, p2 = s2; i < strlen(s2); i++, p2++) n++;
	
	for (i = 0, p1 = s1; i < strlen(s1); i++, p1++) {
		char cut[11];
		c = 0;
		for (j = 0, p2 = s2; j < strlen(s2); j++, p2++) {
			cut[c] = *(p1+j);
			c++;
		}
		if (strcmp(s2, cut) == 0) {
			n = i;
			break;
		}
	}
	printf("%d", n);
}
