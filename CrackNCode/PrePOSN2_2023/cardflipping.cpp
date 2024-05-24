#include <bits/stdc++.h>
using namespace std;

bool a[1000009];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    stack<int> st;
	for (int i = 1; i <= n; i++) {
		if (a[i]) {
			cout << i << " ";
			a[i+1] ^= 1;
			while (!st.empty()) {
				cout << st.top() << " ";
				st.pop();
			}
		}
		else st.push(i);
	}
 	return 0;   
}