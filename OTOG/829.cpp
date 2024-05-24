#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll arr[100009], sum=0;
map<ll,int> m;
vector<ll> temp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, q;
	ll k;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	sum = arr[0]+arr[1]+arr[2];
	m[sum] = 1;
	for (int i = 2; i <= n; i++) {
		sum += arr[i+1]-arr[i-2];
		if (m.find(sum) == m.end()) m[sum] = i;
		else m[sum] = min(m[sum], i);
	}
	for (auto i : m) temp.push_back(i.first);
	for (int i = n-2; i >= 0; i--) m[temp[i]] = min(m[temp[i]], m[temp[i+1]]);
	while (q--) {
		cin >> k;
		int ans = lower_bound(temp.begin(), temp.end(), k)-temp.begin();
		cout << m[temp[ans]] << "\n";
	}
	return 0;
}
