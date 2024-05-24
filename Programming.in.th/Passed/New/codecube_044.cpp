#include <bits/stdc++.h>
using namespace std;

int h[1000009], L[1000009], R[1000009];
stack<int> st;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> h[i];
	for (int i = 1; i <= n; i++) {
		while (!st.empty() && h[i] >= h[st.top()]) {
			L[i] = max(L[i], i-st.top()+L[st.top()]);
			st.pop();
		}
		st.push(i);
	}
	for (int i = n; i >= 1; i--) {
		while (!st.empty() && h[i] >= h[st.top()]) {
			R[i] = max(R[i], st.top()-i+R[st.top()]);
			st.pop();
		}
		st.push(i);
	}
	for (int i = 1; i <= n; i++) cout << L[i]+R[i]+1 << " ";
	return 0;
}