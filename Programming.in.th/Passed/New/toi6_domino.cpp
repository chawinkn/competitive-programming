#include <bits/stdc++.h>
using namespace std;

int n, cnt=0;
vector<string> ans;

void solve(int cnt) {
	if (cnt > n) return;
	if (cnt == n) {
		for (auto i : ans) cout << i << "\n";
		cout << "E\n";
		return;
	}
	ans.push_back("--");
	solve(cnt+1);
	ans.pop_back();
	ans.push_back("||");
	solve(cnt+2);
	ans.pop_back();
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    solve(0);
    return 0;
}
