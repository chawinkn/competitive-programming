#include <bits/stdc++.h>
using namespace std;

string arr[3][3]={
	{"","CAB","FDE"},
	{"IGH","LJK","OMN"},
	{"SPQR","VTU","ZWXY"}
};
vector<char> ans;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, s, h, v, m, x=0, y=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			cin >> s >> m;
			h = (s-1)%3, v = (s-1)/3;
		}
		else cin >> h >> v >> m;
		
		x += h; y += v;
		if (x == 0 && y == 0) {
			while (ans.size() && m--) ans.pop_back();
		}	
		else ans.push_back(arr[y][x][m%arr[y][x].length()]);
	}
	if (ans.size()) {
		for (auto i : ans) cout << i;
	}
	else cout << "null";
	return 0;
}
