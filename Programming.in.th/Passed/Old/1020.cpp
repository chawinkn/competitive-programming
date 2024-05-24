#include <bits/stdc++.h>
using namespace std;

string text;

int check(int a, int b) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int p=1;
    for (int i = a; i < b; i++) {
        char f = text[i];
        char s = text[b-i-1];
        if (f >= 'a' && f <= 'z') {
            f -= 32;
        }
        if (s >= 'a' && s <= 'z') {
            s -= 32;
        }
        if (f != s) {
            p = 0;
            break;
        }
    }
    return p;
}

int main() {
    cin >> text;
    int l = text.length();
    if (check(0, l)) {
        int pf, ps;
        pf = check(0, l/2);
        if (l%2 == 0) {
            ps = check(l/2, l);
        }
        else {
            ps = check(l/2+1, l);
        }
        if (pf && ps) {
            cout << "Double Palindrome";
        }
        else {
            cout << "Palindrome";
        }
    }
    else {
        cout << "No";
    }
}

