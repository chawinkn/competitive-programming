#include <bits/stdc++.h>
using namespace std;

int arr[209];
bool visited[109];

int main() {
    int n, ans=0;
    cin >> n;
    for (int i = 0; i < 2*n; i++) cin >> arr[i];
    for (int i = 0; i < 2*n; i++) {
        if (visited[arr[i]]) continue;
        visited[arr[i]] = true;
        for (int j = i+1; j < 2*n; j++) {
            if (!visited[arr[j]]) ans++;
            if (arr[i] == arr[j]) break;
        }
//        for (int j = 0; j < 2*n; j++) cout << arr[j] << " ";
//        cout << "\n";
    }
	cout << ans;
    return 0;
}