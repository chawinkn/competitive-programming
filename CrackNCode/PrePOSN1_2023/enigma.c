#include <stdio.h>

char s[200009];
int arr[200009];

int main() {
	int n=0, ans=0;
	scanf("%s", s);
	for (int i = 0; s[i] != '\0'; i++) {
		scanf("%d", &arr[i]);
		n++;
	}
	for (int i = 0; i < 26; i++) {
		int cnt[29]={0};
		for (int j = 0; j < n; j++) {
			int k=(s[j]-65+arr[j]*i)%26;
			cnt[k]++;
			if (cnt[k] > ans) ans = cnt[k];
		}
	}
	printf("%d", ans);
	return 0;
}
