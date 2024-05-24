#include <bits/stdc++.h>
using namespace std;

// Queue

queue<int> q, Class[19];
int student[10009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int nc, ns;
	cin >> nc >> ns;
	for (int i = 0; i < ns; i++) {
		int c, s;
		cin >> c >> s;
		student[s] = c;
	}
	char t;
	while (cin >> t) {
		if (t == 'E') {
			int id;
			cin >> id;
			if (Class[student[id]].empty()) q.push(student[id]);
			Class[student[id]].push(id);
		}
		else if (t == 'D') {
			if (q.empty()) cout << "empty\n";
			else {
				cout << Class[q.front()].front() << "\n";
				Class[q.front()].pop();
				if (Class[q.front()].empty()) q.pop();
			}
		}
		else break;
	}
	cout << 0;
	return 0;
}