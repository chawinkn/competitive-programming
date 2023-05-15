#include <bits/stdc++.h>
using namespace std;

char in[10003];

int main() {
    int num, sum=0, ans=INT_MIN;
    while (cin >> in) {
        if (in[0] == 'd') break;
        num = atoi(in);
        sum += num;
        if (sum >= 0) {
            ans = max(ans, sum);
        }
        else sum = 0;
    }
    cout << ans;
    return 0;
}