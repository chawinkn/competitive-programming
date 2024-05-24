#include <bits/stdc++.h>
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, a;
	cin >> n;
	unordered_map<int,int> m;	
	for (int i = 1; i <= n; i++) {
		cin >> a;
		if (m.find(a) == m.end()) m[a] = 1;
		else m[a]++;
	}
	int ans=0;
	for (auto i : m) ans = max(ans, i.second);
	cout << ans;
	return 0;
}