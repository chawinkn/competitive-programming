#include <bits/stdc++.h>
using namespace std;

#define ll long long

map<ll,ll> m;
ll s[200009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll n, t, a, b;
	cin >> n >> t;
	m[0] = n;
	while (t--) {
		cin >> a >> b;
		m[s[a]]--;
		if (m[s[a]] <= 0) m.erase(s[a]);
		s[a] += b;
		m[s[a]]++;
		cout << m.size() << "\n";
	}
	return 0;
}