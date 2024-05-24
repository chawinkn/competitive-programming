#include <iostream>
using namespace std;

int arr[23], n, p, sum=0, found;

void solve(int i) {
    if (i == p) {
        if (sum == n) found = 1;
        return;
    }
    solve(i+1); // Not pick
    sum += arr[i];
    solve(i+1); // Pick
    sum -= arr[i];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> p;
        for (int i = 0; i < p; i++) cin >> arr[i];
        found = 0;
        solve(0);
        if (found) cout << "YES!\n";
        else cout << "NO\n";
    }
    return 0;
}