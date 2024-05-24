#include <bits/stdc++.h>
using namespace std;

int n, m, num, p[9];

void food(int l, string s, int v[]) {
	if (l == n) {
		if (p[s[0]-'0']) return;
		for (auto i : s) cout << i << " ";
		cout << "\n";
	}
	for (int i = 1; i <= n; i++) {
		if (!v[i]) {
			v[i] = 1;
			string temp=s;
			temp += i+'0';
			food(l+1, temp, v);
			v[i] = 0;
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> num;	
		p[num] = 1;
	}
	int v[9]={0};
	food(0, "", v);
	return 0;
}

