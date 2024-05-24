#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, x;
	cin >> n;
	vector<int> idx(n+1, 0);
	for (int i = 0; i < n; i++) {
		cin >> x;	
		idx[x] = i;
	}
	int ans=1;
	for (int i = 1; i <= n; i++) {
		if (idx[i] < idx[i-1]) ans++;
	}
	cout << ans;
	return 0;
}