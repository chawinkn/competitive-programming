#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll cnt[200009];

int main() {
	int n, a, num;
	ll ans=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		cnt[num]++;
	}
	cin >> a;
	for (int i = 0; i <= a/2; i++) {
		if (a-i != i) ans += cnt[i]*cnt[a-i];
		else ans += (cnt[i]*(cnt[i]-1))/2;	
	}
	cout << ans;
	return 0;
}
