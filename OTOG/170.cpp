#include <bits/stdc++.h>
using namespace std;

pair<int,int> chord[5059];
int guitar[109];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int x, y, z, k;
    cin >> x >> y >> z;
    for (int i = 1; i <= y; i++) cin >> chord[i].first >> chord[i].second;
	while (z--) {
		cin >> k;
		guitar[chord[k].first]++;
		guitar[chord[k].second+1]--;
	}
	for (int i = 1; i <= x; i++) {
		guitar[i] += guitar[i-1];
		cout << guitar[i] << "\n";
	}
    return 0;
}