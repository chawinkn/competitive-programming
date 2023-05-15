#include <stdio.h>
#include <string.h>

int main() {
	char s[14], card[18];
	scanf("%s", s);
	for (int i = 0, j = 0; i < 13; i++, j++) {
		if (i == 0 || i == 4 || i == 9 || i == 11) {
			card[j] = s[i];
			j++;
			card[j] = '-';
		}
		else {
			card[j] = s[i];
		}
	}
	printf("%s", card);
}
