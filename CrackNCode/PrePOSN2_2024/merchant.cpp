#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n, m, p;
ll v[100009], w[100009], W[100009];

// 42/100

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m >> p;
	ll l=0, r=0;
	for (int i = 1; i <= n; i++) {
		cin >> v[i] >> w[i];
		v[i] += v[i-1];
		W[i] = w[i]+W[i-1];
	}
	ll ans=-1e18;
	for (int i = 1; i+m-1 <= n; i++) {
		int j=i+m-1;
		l = 0;
		r = W[j]-W[i-1];
		while (l < r) {
	        ll mid=(l+r)/2, sum=0;
		    int cnt=1;
		    for (int k = i; k <= j; k++) {
		    	sum += w[k];
		        if (sum > mid) {
		            cnt++;
		            sum = w[k];
		        }
		    }
	        if (cnt <= p) r = mid;
	        else l = mid + 1;
	    }
	    ans = max(ans, (v[j]-v[i-1])-l*l);
	}
	cout << ans;
	return 0;
}