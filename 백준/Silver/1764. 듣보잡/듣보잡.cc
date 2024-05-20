#include <iostream>
#include <map>
using namespace std;

int n, m, cnt;
string s;
map<string, int> um;

int main() {
    cin >> n >> m;
    while (n--) {
        cin >> s;
        ++um[s];
    }
    while (m--) {
        cin >> s;
        ++um[s];
        if (um[s] == 2) ++cnt;
    }
    cout << cnt << '\n';
    for (auto p : um)
        if (p.second == 2) cout << p.first << '\n';
}