#include <bits/stdc++.h>
using namespace std;

string in;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int u;
    while (getline(cin, in)) {
        if (in == "#") break;
        vector<int> g[29];
        int visited[29]={0};
        for (int i = 0; i < in.length(); i++) {
            if (in[i] == ':') {
                u = in[i-1];
                i++;
                while (in[i] != ';' && in[i] != '.') {
                    g[u-'A'].push_back(in[i]-'A');
                    i++;
                }
            }
        }
        int i, minotaur, theseus, k=0, d=1, cnt=0;
        for (i = 0; i < in.length(); i++) {
            if (in[i] == '.') {
                minotaur = in[i+2]-'A';
                theseus = in[i+4]-'A';
                int j =in.length()-1;
                while (j > i+5) {
                    k += d*(in[j]-'0');
                    d *= 10;
                    j--;
                }
                break;
            }
        }
        while (1) {
            int v=-1;
            for (auto i : g[minotaur]) {
                if (!visited[i] && i != theseus) {
                    v = i;
                    break;
                }
            }
            if (v == -1) {
                cout << "/" << (char)(minotaur+'A') << "\n";
                break;
            }
            cnt++;
            theseus = minotaur;
            minotaur = v;
            if (cnt == k) {
                cout << (char)(theseus+'A') << " ";
                visited[theseus] = 1;
                cnt = 0;
            }
        }
    }
    return 0;
}