#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, num, ans=0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (num == 0) ans = 1;
    }
    cout << ans;
    return 0;
}
