#include <stdio.h>
#include <string.h>

int main() {
	char s[100001];
	scanf("%s", s);
	int n = strlen(s), p=1;
	for (int i = 0; i < n; i++) {
		if (s[i] != s[n-i-1]) {
			p = 0;
			break;
		}
	}
	if (p) {
		printf("Yes");
	}
	else {
		printf("No");
	}
}
