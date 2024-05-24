#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

deque<pair<int,int>> dq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, x;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		while (!dq.empty() && dq.back().f >= x) dq.pop_back();
		if (!dq.empty()) cout << dq.back().s << " ";
		else cout << "0 ";
		dq.push_back({x, i});
	}
	return 0;
}