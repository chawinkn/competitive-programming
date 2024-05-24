#include <stdio.h>

int main() {
	char s[21];
	int n=0;
	printf("Enter string : ");
	gets(s);
	while (s[n] != '\0') {
		n++;	
	}
	printf("Reverse = ");
	for (int i = n-1; i > -1; i--) {
		printf("%c", s[i]);	
	}
}
