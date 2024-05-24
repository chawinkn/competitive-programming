#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int q, n, l, r;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    while (q--) {
    	cin >> l >> r;
    	vector<int> tmp=a;
    	sort(tmp.begin()+l, tmp.begin()+r+1);
    	for (int i = l; i <= r; i++) cout << tmp[i] << " ";
    	cout << "\n";
	}
    return 0;
}