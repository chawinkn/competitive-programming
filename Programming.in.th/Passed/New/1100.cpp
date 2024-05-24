#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll cnt[1009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	ll ans=0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		cnt[a]++;
	}
	for (int i = 0; i <= 999; i++) {
		if (!cnt[i]) continue;
		ans += (cnt[i]*(cnt[i]-1))/2;
		for (int j = i+1; j <= 999; j++) {
			if (i%10 == j%10 || (i/10)%10 == (j/10)%10 || i/100 == j/100) ans += cnt[i]*cnt[j]; 
		}
	}
	cout << ans;
	return 0;
}