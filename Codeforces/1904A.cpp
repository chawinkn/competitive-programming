#include <bits/stdc++.h>
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, a, b, xk, yk, xq, yq;
	cin >> t;
	while (t--) {
		cin >> a >> b >> xk >> yk >> xq >> yq;
		set<pair<int,int>> k, q;
		vector<pair<int, int>> move = {
	        {a, b}, {-a, b}, {a, -b}, {-a, -b},
	        {b, a}, {-b, a}, {b, -a}, {-b, -a}
	    };
	    int ans=0;
	    for (auto i : move) {
	    	k.insert({xk-i.first, yk-i.second});
			q.insert({xq-i.first, yq-i.second});	
		}
		for (auto i : k) {
			if (q.find(i) != q.end()) ans++;
		}
		cout << ans << "\n";
	}
	return 0;
}