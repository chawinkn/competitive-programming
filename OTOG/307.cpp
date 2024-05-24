#include <bits/stdc++.h>
using namespace std;

int change(int v, int n, int c[], int m[]) {
	if (m[v] != 0) return m[v];
	if (v == 0) return 0;
	int min = v;
	for (int i = 0; i < n; i++) {
		if (c[i] <= v) {
			int cnt = 1 + change(v - c[i], n, c, m);
			if (cnt < min) {
				min = cnt;
			}
		}
	}
	m[v] = min;
	return min;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int v, n;
	cin >> n >> v;
	int c[n], m[v+1] = {0};
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	cout << change(v, n, c, m);
	return 0;
}
