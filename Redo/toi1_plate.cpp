#include <bits/stdc++.h>
using namespace std;

int S[1009];
queue<int> C[19], q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int nc, ns;
	cin >> nc >> ns;
	while (ns--) {
		int c, s;
		cin >> c >> s;
		S[s] = c;
	}
	while (true) {
		char t;
		cin >> t;
		if (t == 'E') {
			int id;
			cin >> id;
			if (C[S[id]].empty()) {
				q.push(S[id]);
			}
			C[S[id]].push(id);
		}
		else if (t == 'D') {
			if (!q.empty()) {
				cout << C[q.front()].front() << "\n";
				C[q.front()].pop();
				if (C[q.front()].empty()) q.pop();
			}
			else cout << "empty\n";
		}
		else {
			cout << "0";
			break;
		}
	}
	return 0;
}