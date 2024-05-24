#include <bits/stdc++.h>
using namespace std;
 
int c[5]={100,20,10,5,1};
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, ans=0;
	cin >> n;
	for (auto i : c) {
		ans += n/i;
		n -= i*(n/i);
	}
	cout << ans;
	return 0;
}