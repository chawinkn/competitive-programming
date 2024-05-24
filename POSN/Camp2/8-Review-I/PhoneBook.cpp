#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

multimap<string, string> m;

int main() {
    int n, f;
    string name, num;
    cin >> n >> f;
    while (n--) {
        cin >> name >> num;
        m.insert({name, num});
    }
    while (f--) {
        cin >> name;
        if (m.find(name) != m.end()) {
            vector<string> temp;
            for (auto it = m.begin(); it != m.end(); it++) {
                if (it->first == name) temp.push_back(it->second);
            }
            sort(temp.begin(), temp.end());
            for (auto i : temp) {
                cout << name << " " << i << "\n";
            }
        }
        else cout << name << " -\n";
    }
    return 0;
}
