#include <bits/stdc++.h>
using namespace std;

int arr[500009];
vector<int> p, prime(1000009, true);

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k, cnt=0;
	cin >> n >> k;
	prime[1] = false;
	for (int i = 2; i <= 1e6; i++) {
		if (prime[i]) {
			for (int j = 2*i; j <= 1e6; j+=i) prime[j] = false;
		}
	}
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (prime[arr[i]]) p.push_back(i);
	}
	int ans=1e6;
	for (int i = 0; i <= p.size()-k; i++) ans = min(ans, p[i+k-1]-p[i]+1);
	cout << ans;
	return 0;
}
