#include <bits/stdc++.h>
using namespace std;

// Heap

priority_queue<int> pq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int p;
	cin >> p;
	while (p--) {
		char t;
		cin >> t;
		if (t == 'A') {
			int d;
			cin >> d;
			pq.push(-d);
		}
		else {
			if (pq.empty()) cout << -1;
			else {
				cout << -pq.top();
				pq.pop();
			}
			cout << "\n";
		}
	}
	return 0;
}