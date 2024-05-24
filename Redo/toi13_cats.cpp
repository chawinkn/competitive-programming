#include <bits/stdc++.h>
using namespace std;

int s[2000009];

int main() {
   ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	int l=0, r=0;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		r = max(r, s[i]);	
	}
	while (l < r) {
		int m=l+(r-l)/2;
		stack<int> st;
		bool valid=true;
		for (int i = 1; i <= n; i++) {
			if (s[i] <= m) continue;
			if (st.empty()) st.push(s[i]);
			else {
				if (s[i] == st.top()) st.pop();
				else {
					valid = false;
					break;
				}
			}
		}
		if (valid) r = m;
		else l = m+1;
	}
	cout << l;
	return 0;
}