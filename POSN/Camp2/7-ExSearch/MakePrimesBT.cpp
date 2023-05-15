#include <iostream>
using namespace std;

int ans=33;
string n;

void search(string n, int l, int k) {
    int m=n.length();
    if (l == 0) return;
    int num=0, d=1, isPrime=1;
    for (int i = m-1; i >= 0; i--) {
        if (n[i] != 'X') {
            num += d*(n[i]-'0');
            d *= 10;
        }
    }
    for (long long int i = 2; i*i <= num; i++) {
        if (num%i == 0) {
            isPrime = 0;
            break;
        }
    }
    if (isPrime) ans = min(ans, k);
    for (int i = 0; i < m; i++) {
        if (n[i] != 'X') {
            string temp=n;
            temp[i] = 'X';
            search(temp, l-1, k+1);
        }
    }
}

int main() {
    cin >> n;
    search(n, n.length(), 0);
    if (ans < 33) cout << ans;
    else cout << -1;
    return 0;
}