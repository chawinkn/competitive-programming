#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, ans=0;
    string s;
    cin >> n >> s;
    char state='0';
    for (int i = 0; i < n; i++) {
        if (s[i] == state) {
            state = (state == '0') ? '1' : '0';
            ans++;
        }
    }
    cout << ans;
    return 0;
}
