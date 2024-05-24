#include<bits/stdc++.h>

using namespace std;

int x[100009], h[100009];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i] >> h[i];
    int idx=0, mx=0;
    char d='L';
    for (int i = n-1; i >= 0; i--) {
    	int k=lower_bound(x, x+n, x[i]-h[i])-x;
		cout << x[i]-h[i] << " " << k << "\n";
	}
	cout << idx << " " << d;
    return 0;
}
