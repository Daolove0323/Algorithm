#include <iostream>
#include <map>
#include <string>
using namespace std;

int t, n, answer = 1;
string item, where;
map<string, int> m;

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> item >> where;
            ++m[where];
        }
        for (auto i : m)
            answer *= (i.second + 1);
        cout << answer - 1 << '\n';
        answer = 1;
        m.clear();
    }
  
}