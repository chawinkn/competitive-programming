#include <bits/stdc++.h>
using namespace std;

vector<int> arr;

int main() {
	int x, m, c, k, cnt=0;
    cin >> x >> m;
    while (m--) {
        cin >> c;
        arr.push_back(c);
    }
    for (int i = arr.size()-1; i >= 0; i--) {
        if (x >= arr[i]) {
            k = x/arr[i];
            x -= arr[i]*k;
            cnt += k;
        }
    }
    cout << cnt;
}