#include <bits/stdc++.h>
using namespace std;

int arr[100001];

vector<int> minheap={INT_MIN}, maxheap={INT_MAX};

int main() {
    int n, a=1, b=1;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) {
        if (arr[i] >= minheap[a/2]) {
            minheap.push_back(arr[i]);
            a++;
        }
        if (arr[i] <= maxheap[b/2]) {
            maxheap.push_back(arr[i]);
            b++;
        }
    }
    cout << a-1 << " " << b-1;
    return 0;
}
