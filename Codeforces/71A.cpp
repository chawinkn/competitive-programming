#include <bits/stdc++.h>
using namespace std;
 
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s.length() > 10) {
            cout << s[0] << s.length()-2 << s[s.length()-1]<< "\n";
        }
        else {
            cout << s << "\n";
        }
    }
    return 0;
}