#include <bits/stdc++.h>
using namespace std;

int parent[100009], arr[100009];

int find(int u) {
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, a, b;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		parent[i] = i;	
	}
	while (m--) {
		cin >> a >> b;
		a = find(a);
		b = find(b);
		if (a != b) {
			if (arr[a] > arr[b]) {
				arr[a] += arr[b]/2;
				parent[b] = a;
				cout << a;
			}
			else if (arr[a] < arr[b]) {
				arr[b] += arr[a]/2;
				parent[a] = b;
				cout << b;
			}
			else {
				arr[min(a, b)] += arr[max(a, b)]/2;
				parent[max(a, b)] = min(a, b);
				cout << min(a, b);
			}
		}
		else cout << -1;
		cout << "\n";
	}
	return 0;
}
