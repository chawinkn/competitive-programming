#include <bits/stdc++.h>
using namespace std;

#define ll long long

// 40/100

const int M = 5454541;
int a[109];
set<int> s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i], s.insert(a[i]);
	if (s.size() == 1) {
		int b=1;
		for (int i = 0; i < n; i++) b *= 2, b %= M;
		cout << b-1;
		return 0;
	}
	int ans=0;
	for (int i = 0; i < 1<<n; i++) {
		ll sum=0;
		int cnt=0;
		for (int j = 0; j < n; j++) {
			if (i&(1<<j)) sum += a[j], cnt++;
		}
		if (cnt != 0 && sum%cnt == 0) ans++, ans %= M;
	}
	cout << ans;
	return 0;
}