#include <bits/stdc++.h>
using namespace std;

#define ll long long

map<ll,ll> mp;

int main() {
    int n;
	scanf("%d", &n);
    while (n--) {
    	ll s, c;
		scanf("%lld %lld", &s, &c);
    	mp[s] = c;
	}
	ll ans=0;
	for (auto [i,j] : mp) {
		if (j%2 == 1) ans++;
		if (j > 1) mp[i*2] += j/2;
	}
	printf("%lld", ans);
    return 0;
}