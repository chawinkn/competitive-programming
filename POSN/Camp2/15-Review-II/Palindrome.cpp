#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n=s.length();
    for (int i = 0; i < n/2; i++) {
        if (s[i] != s[n-i-1]) {
            cout << "Your string is not a palindrome.";
            return 0;
        }
    }
    cout << "Your string is a palindrome.";
    return 0;
}
