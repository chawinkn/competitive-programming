#include <bits/stdc++.h>
using namespace std;

int v[10001];
queue<int> r[12], q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int nc, ns, c, s, id;
	char t;
	cin >> nc >> ns;
	for (int i = 0; i < ns; i++) {
		cin >> c >> s;
		v[s] = c;
	}
	while (true) {
		cin >> t;
		if (t == 'E') {
			cin >> id;
			if (r[v[id]].empty()) {
				q.push(v[id]);
			}
			r[v[id]].push(id);
		}
		else if (t == 'D') {
			if (!q.empty()) {
				cout << r[q.front()].front() << "\n";
				r[q.front()].pop();
				if (r[q.front()].empty()) {
					q.pop();
				}
			}
			else {
				cout << "empty\n";
			}
		}
		else if (t == 'X') {
			cout << 0;
			break;
		}
	}
	return 0;
}
