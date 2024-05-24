#include <bits/stdc++.h>
using namespace std;

queue<int> q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> v;
	for (int i = 1; i <= n; i++) q.push(i);
	int cnt=0;
	while (!q.empty()) {
		cnt++;
		if (cnt == m) {
			cnt = 0;
			cout << q.front() << " ";
		}
		else q.push(q.front());
		q.pop();
	}
	return 0;	
}