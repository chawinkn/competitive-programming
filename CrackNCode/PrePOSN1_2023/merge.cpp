#include <bits/stdc++.h>
using namespace std;
 
// 30/100 
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, v, c, d, sum=0;
	cin >> n >> c >> d;
	for (int i = 0; i < n; i++) {
		cin >> v;
		sum += v;
	}
	if (sum%2) cout << "Yes";
	else cout << "No";
	return 0;
}