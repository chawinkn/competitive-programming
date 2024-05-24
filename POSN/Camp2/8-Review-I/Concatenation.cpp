#include <iostream>
#include <algorithm>
using namespace std;

string arr[100003];

bool cmp(string a, string b) {
    return a+b < b+a;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n, cmp);
    for (int i = 0; i < n; i++) {
        cout << arr[i];
    }
    return 0;
}
