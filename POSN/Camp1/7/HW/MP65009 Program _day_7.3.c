#include <stdio.h>

int main() {
	char s1[11], s2[11], *sp1, *sp2;
	int i, cnt1[26]={0}, cnt2[26]={0}, anagram=1;
	scanf("%s", s1);
	scanf("%s", s2);
	for (i = 0, sp1 = s1; *sp1 != '\0'; i++, sp1++) {
		cnt1[*sp1-'a']++;
	}
	for (i = 0, sp2 = s2; *sp2 != '\0'; i++, sp2++) {
		cnt2[*sp2-'a']++;
	}
	for (i = 0; i < 26; i++) {
		if (cnt1[i] != cnt2[i]) {
			anagram = 0;
			break;
		}
	}
	if (anagram) {
		printf("yes");
	}
	else {
		printf("no");
	}
}
