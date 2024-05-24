#include <bits/stdc++.h>
using namespace std;

int M[100009];
vector<int> c[100009], p[100009];
bool banned[100009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N, T;
	cin >> N >> T;
	for (int i = 0; i < N; i++) {
		int C;
		cin >> M[i] >> C;
		while (C--) {
			int k;
			cin >> k;
			c[i].push_back(k), p[k].push_back(i);
		}
	}
	int l=0, r=1e9;
	while (l < r) { 
		int K=l+(r-l)/2, cnt=0;
		memset(banned, false, sizeof(banned));
		for (int i = 0; i < N; i++) {
			if (M[i] <= K) continue;
			banned[i] = true;
			for (auto j : c[i]) banned[j] = true;
			for (auto j : p[i]) banned[j] = true;
		}
		for (int i = 0; i < N; i++) cnt += !banned[i];
		if (cnt >= T) r = K;
		else l = K+1;
	}
	cout << l;
	return 0;
}