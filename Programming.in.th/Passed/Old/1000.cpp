#include <bits/stdc++.h>
using namespace std;

string word[30001];

int main() {
    int l, n, d, founded=0;
    cin >> l >> n;
    for (int i = 0; i < n; i++) cin >> word[i];
    for (int i = 0; i < n-1; i++) {
        d = 0;
        if (!founded) {
            for (int j = 0; j < l; j++) {
                if (word[i][j] != word[i+1][j]) d++;
            }
            if (d > 2) {
                cout << word[i];
                founded++;
            }
        }
        else break;
    }
    if (n == 1) cout << word[0];
    else if (!founded) cout << word[n-1];
    return 0;
}
