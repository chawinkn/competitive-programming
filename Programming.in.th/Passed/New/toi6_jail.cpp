#include <bits/stdc++.h>
using namespace std;

queue<int> q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, cnt=0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) q.push(i);
	while (!q.empty()) {
		cnt++;
		if (cnt == m) {	
			cout << q.front() << " ";
			cnt = 0;
		}
		else q.push(q.front());
		q.pop();
	}
	return 0;
}
