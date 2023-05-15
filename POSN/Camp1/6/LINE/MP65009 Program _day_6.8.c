#include <stdio.h>

int main() {
	char s[101], u[101];
	int l, c=0, vowels[5]={0};
	printf("Input String1    ==> ");
	gets(s);
	for (l = 0; s[l] != '\0'; l++) {
		char n = s[l];
		// Lower to upper
		if (n >= 'a' && n <= 'z') {
			n -= 'a' - 'A';	
		}
		if ((n >= '0' && n <= '9') || (n >= 'A' && n <= 'Z')) {
			u[l] = n;
			c++;
			if (n == 'A') vowels[0]++;
			else if (n == 'E') vowels[1]++;
			else if (n == 'I') vowels[2]++;
			else if (n == 'O') vowels[3]++;
			else if (n == 'U') vowels[4]++;
		}
		else {
			u[l] = s[l];
		}
	}
	printf("Lenght of String ==> %2d Characters\n", l);
	printf("Reverse String   ==> ");
	for (int i = l-1; i > -1; i--) {
		printf("%c", s[i]);
	}
	printf("\nUpper String\t ==> %s\n", u);
	printf("=-=-=-=-=-=-=-=-=-=\nNumber of vowel\n=-=-=-=-=-=-=-=-=-=\n");
	printf("A or a = %d\n", vowels[0]);
	printf("E or e = %d\n", vowels[1]);
	printf("I or i = %d\n", vowels[2]);
	printf("O or o = %d\n", vowels[3]);
	printf("U or u = %d\n", vowels[4]);
	printf("=-=-=-=-=-=-=-=-=-=");
}
