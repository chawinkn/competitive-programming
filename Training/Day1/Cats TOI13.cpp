#include <bits/stdc++.h>
using namespace std;

// Binary Search + Stack

int sz[2000009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	int l=0, r=1;
	for (int i = 1; i <= n; i++) cin >> sz[i], r = max(r, sz[i]);
	while (l < r) {
		int m=l+(r-l)/2;
		bool valid=true;
		stack<int> st;
		for (int i = 1; i <= n; i++) {
			if (m >= sz[i]) continue;	
			if (st.empty()) st.push(sz[i]);
			else if (st.top() == sz[i]) st.pop();
			else {
				valid = false;
				break;
			}
		}
		if (valid) r = m;
		else l = m+1;
	}
	cout << l;
	return 0;
}