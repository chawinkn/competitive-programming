#include <bits/stdc++.h>
using namespace std;

vector<int> arr;

int main() {
    int n, num;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        arr.push_back(num);
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}
