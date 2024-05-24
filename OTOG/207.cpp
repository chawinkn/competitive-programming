#include <bits/stdc++.h>
using namespace std;

int qs[1009];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q, a, b;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
    	cin >> qs[i];
    	qs[i] += qs[i-1];
	}
	while (q--) {
		cin >> a >> b;
		cout << qs[b]-qs[a-1] << "\n";
	}
    return 0;
}