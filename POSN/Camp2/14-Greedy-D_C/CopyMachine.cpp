#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

pair<int,int> arr[100009]; // t w
int v[100009];

int main() {
    int n;
    long long int c=0, ans=0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i].f >> arr[i].s;
    // sort(arr, arr+n);
    for (int i = 0; i < n; i++) {
        printf("%f\n", arr[i].s/arr[i].f);
    }
    return 0;
}