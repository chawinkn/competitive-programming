#include <bits/stdc++.h>
using namespace std;

string text, pattern;
int last[10003];

int main() {
    int n, m, i, j;
    cin >> text >> pattern;
    n = text.length();
    m = pattern.length();
    i = m-1;
    j = m-1;
    while (i <= n-1) {
        if (pattern[j] == text[i]) {
            if (j == 0) {
                
            }
            else {
                i--;
                j--;
            }
        }
        else {

        }
    }
    return 0;
}