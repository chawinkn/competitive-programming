#include <bits/stdc++.h>
using namespace std;

string arr[10003];

int main() {
    int n, check=0;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    for (int i = 0; i < n-1; i++) {
//        cout << arr[i] << "\n";
        int cnt=0;
        for (int j = 0; j < arr[i].length(); j++) {
            if (arr[i][j] == arr[i+1][j]) cnt++;
        }
        if (cnt == arr[i].length()) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}
