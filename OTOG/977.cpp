#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll x[200009], y[200009];
vector<int> circle;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    ll zx, zy, r;
    cin >> n >> zx >> zy >> r;
    for (int i = 0; i < n; i++) {
    	cin >> x[i] >> y[i];
    	if ((x[i]-zx)*(x[i]-zx)+(y[i]-zy)*(y[i]-zy) <= r*r) circle.push_back(i);
	}
	ll s=1e18, e=1e18;
	for (auto i : circle) {
		s = min(s, abs(x[0]-x[i])+abs(y[0]-y[i]));
		e = min(e, abs(x[n-1]-x[i])+abs(y[n-1]-y[i]));
	}
	cout << min(s+e, abs(x[0]-x[n-1])+abs(y[0]-y[n-1]));
 	return 0;   
}