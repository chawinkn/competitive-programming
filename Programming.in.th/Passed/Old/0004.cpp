#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	int cp=0, sm=0;
	cin >> s;
	for (auto i : s) {
		if (i >= 'A' && i <= 'Z') cp = 1;
		else sm = 1;
	}
	if (cp && sm) cout << "Mix";
	else if (cp) cout << "All Capital Letter";
	else cout << "All Small Letter";
	return 0;
}
