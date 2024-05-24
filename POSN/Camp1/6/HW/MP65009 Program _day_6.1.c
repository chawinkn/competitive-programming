#include <stdio.h>

int main() {
	char s[21], c;
	int v=0;
	printf("Enter string : ");
	gets(s);
	for (int i = 0; s[i] != '\0'; i++) {
		c = s[i];
		if (s[i] >= 'A' && s[i] <= 'Z') {
			c += 'a' - 'A';	
		}
		if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u') {
			v++;	
		}
	}
	printf("Vowels in %s = %d", s, v);
}
