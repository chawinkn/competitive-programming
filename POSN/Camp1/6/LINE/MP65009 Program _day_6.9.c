#include <stdio.h>

int main() {
	int j=0, d, sum=0;
	char s[20];
	scanf("%s", s);
	for (int i = 0; i < 19; i++) {
		if (s[i] != '-') {
			if (j%2==0) {
				d = 2*(s[i]-'0');
				if (d <= 9) {
					sum += d;
				}
				else {
					sum += 1+(d%10);
				}
			}
			else {
				d = s[i]-'0';
				sum += d;
			}
			j++;
		}
	}
	if (sum%10 == 0) {
		printf("%s is valid card", s);
	}
	else {
		printf("%s is invalid card", s);
	}
}
