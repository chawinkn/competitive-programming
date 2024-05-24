#include <bits/stdc++.h>
using namespace std;

priority_queue<int> pq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, i;
	char t;
	cin >> n;
	while (n--) {
		cin >> t;
		if (t == 'P') {
			cin >> i;
			pq.push(i);
		}
		else {
			if (pq.empty()) cout << "-1\n";
			else {
				cout << pq.top() << "\n";	
				pq.pop();	
			}
		}
	}
	return 0;	
}