#include <bits/stdc++.h>
using namespace std;

#define ll long long

int x[200009];
map<int,int> v;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		v[x[i]] = 0;	
	}
	ll ans=0;
	int l=0, cnt=0;
	for (int i = 0; i < n; i++) {
		if (!v[x[i]]) cnt++;
		v[x[i]]++;
		while (cnt > k) {
			v[x[l]]--;
			if (!v[x[l]]) cnt--;
			l++;
		}
		ans += i-l+1;
	}
	cout << ans;
	return 0;
}