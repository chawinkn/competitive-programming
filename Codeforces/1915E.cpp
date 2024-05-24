#include <bits/stdc++.h>
using namespace std;
 
long long arr[200009];
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, n;
	cin >> t;
	while (t--) {
		long long sum=0;
		map<long long,int> m;
		bool found=false;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> arr[i];
		m[0] = 1;
		for (int i = 1; i <= n; i++) {
			if (i%2) sum -= arr[i];
			else sum += arr[i];
			if (m[sum]) {
				found = true;
				break;
			}
			m[sum] = 1;
		}
		if (found) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}